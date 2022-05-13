/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:49:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 15:40:09 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_all_red_out(t_parstab tab)
{
	int		i;
	t_lexer	*buff;

	i = 0;
	while (tab[i])
	{
		buff = tab[i];
		while (buff)
		{
			if (buff->symbol == red_out || buff->symbol == append)
				open_files(buff->symbol, buff);
		buff = buff->next;
		}
		i++;
	}
}

t_exec	init_struct_exec(t_lexer *ls, char **env)
{
	t_exec		ex;
	t_symbol	symbout;
	t_symbol	symbin;

	ex.envp = env;
	if (api_last_red_in(ls) != NULL)
	{
		symbin = api_get_symbin(ls);
		if (symbin == red_out)
			ex.fd_in = open(api_last_red_in(ls), O_RDONLY, 0644);
		else if (symbin == heredoc)
			ex.fd_in = heredoc;
	}
	else
		ex.fd_in = STDIN_FILENO;
	if (api_last_red_out(ls) == NULL)
		ex.fd_out = STDOUT_FILENO;
	else if (api_last_red_out(ls) != NULL)
	{
		symbout = api_get_symb(ls);
		if (symbout == red_out)
			ex.fd_out = open(api_last_red_out(ls), O_RDWR | O_CREAT
					| O_TRUNC, S_IRWXU);
		else if (symbout == append)
			ex.fd_out = open(api_last_red_out(ls), O_RDWR | O_CREAT
					| O_APPEND, S_IRWXU);
	}
	return (ex);
}

void	wait_all(t_parstab tab, t_exec *ex)
{
	int		status;
	int		pid;
	int		i;

	i = 0;
	while (tab[i])
	{
		pid = waitpid(0, &status, 0);
		if (pid == 0)
			continue ;
		if (ex->fd_out > STDOUT_FILENO)
			close(ex->fd_out);
		if (ex->fd_in > STDIN_FILENO)
			close(ex->fd_in);
		i++;
	}
}

void	pipex(t_parstab	parsing, char **envp)
{
	int		i;
	t_exec	ex;
	int		pip[2];

	open_all_red_out(parsing);
	i = 0;
	if (parsing[i + 1] == NULL
		&& (is_a_builtin(api_command_name(parsing[i])) == 1))
		exec_builtin_alone(api_command_name(parsing[i]), parsing, i, envp);
	else
	{
		while (parsing[i])
		{
			if (pipe(pip) == -1)
				return ;
			ex = init_struct_exec(parsing[i], envp);
			if (check_fd(&ex) == 0)
				exec_cmd(parsing, &ex, i, pip);
			i++;
		}
		wait_all(parsing, &ex);
		close(0);
	}
}
