/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:49:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 18:09:07 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	open_all_red_out(t_lexer *ls)
{
	t_lexer	*buff;

	buff = ls;
	while (buff)
	{
		if (buff->symbol == red_out || buff->symbol == append)
			open_files(buff->symbol, buff);
		buff = buff->next;
	}
}

void	init_red_out_struct(t_exec *ex, t_lexer *ls)
{
	t_symbol	symbout;

	symbout = api_get_symb(ls);
	if (symbout == red_out)
		ex->fd_out = open(api_last_red_out(ls), O_RDWR | O_CREAT
				| O_TRUNC, 0644);
	else if (symbout == append)
		ex->fd_out = open(api_last_red_out(ls), O_RDWR | O_CREAT
				| O_APPEND, 0644);
}

t_exec	init_struct_exec(t_lexer *ls, char **env)
{
	t_exec		ex;
	t_symbol	symbin;

	ex.envp = env;
	if (api_last_red_in(ls) != NULL)
	{
		symbin = api_get_symbin(ls);
		if (symbin == red_in)
			ex.fd_in = open(api_last_red_in(ls), O_RDONLY, 644);
		else if (symbin == heredoc)
			ex.fd_in = -2;
	}
	else
		ex.fd_in = STDIN_FILENO;
	if (api_last_red_out(ls) == NULL)
		ex.fd_out = STDOUT_FILENO;
	else if (api_last_red_out(ls) != NULL && ex.fd_in != -1)
		init_red_out_struct(&ex, ls);
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
		set_ret_value((int)WEXITSTATUS(status));
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
			if (check_fd(&ex, parsing, i) == 0)
			{
				open_all_red_out(parsing[i]);
				exec_cmd(parsing, &ex, i, pip);
			}
			i++;
		}
		wait_all(parsing, &ex);
		close(0);
	}
}
