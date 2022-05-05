/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:48:58 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/05 17:07:59 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_files(t_symbol sb, t_lexer *ls)
{
	int	file;

	file = 0;
	if (sb == red_in)
		file = open(ls->next->content, O_RDONLY, 0777);
	else if (sb == red_out)
		file = open(ls->next->content, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (sb == append)
		file = open(ls->next->content, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else
		return (file);
	return (file);
}

void	open_all_red_out(t_lexer *buff)
{
	while (buff)
	{
		if (buff->symbol == red_out)
			open_files(red_out, buff);
		buff = buff->next;
	}
}

void	redirect(t_parstab tab, t_exec *ex, int i)
{
	close(ex->pip[READ]);
	if (ex->fd_in != -1 && ex->fd_in != -2)
	{
		dup2(ex->fd_in, STDIN_FILENO);
		close(ex->fd_in);
	}
	else if (ex->fd_in == -2 && i > 0)
	{
		dup2(ex->pip[READ], STDIN_FILENO);
	}
	if (ex->fd_out != -1 && ex->fd_out != -2)
	{
		dup2(ex->fd_out, STDOUT_FILENO);
		close(ex->fd_out);
	}
	else if (ex->fd_out == -2 && tab[i + 1] != NULL)
	{
		dup2(ex->pip[WRITE], STDOUT_FILENO);
	}
}

void	child_process(t_parstab tab, t_exec *ex, int i)
{
	char	*path;
	char	**cmd;

	cmd = api_full_command(tab[i]);
	path = prep_path(cmd[0], ex->envp);
	/*if (is_a_builtin(cmd[0]))
	{
		ft_putstr_fd("builtin connard", 0);
		//redirect()
		//exec_builtin_w_pipe()
	}*/
	if (path)
	{
		redirect(tab, ex, i);
		if (execve(path, cmd, ex->envp) == -1)
			ft_putstr_fd("command nf", 0);
	}
	else
		printf("command not found : %s\n", cmd[0]);
	return ;
	//free tout ce merdier si possible
}

//void	parent_process()

void	exec_cmd(t_parstab tab, t_exec *ex, int i)
{
	int		pid1;

	pid1 = fork();
	if (pid1 < 0)
		return ;
	else if (pid1 == 0)
	{
		child_process(tab, ex, i);
	}
	/*else
		printf("parent procc\n");
		parent_process();*/
	waitpid(pid1, NULL, 0);
}
