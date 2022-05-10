	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:48:58 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/09 18:46:44 by tgeorgin         ###   ########.fr       */
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
		if (buff->symbol == red_out || buff->symbol == append)
			open_files(buff->symbol, buff);
		buff = buff->next;
	}
}

void	redirect(t_parstab tab, t_exec *ex, int i, int *pip)
{
	close(pip[READ]);
	if (ex->fd_in != -1 && ex->fd_in != STDIN_FILENO)
	{
		dup2(ex->fd_in, STDIN_FILENO);
		close(ex->fd_in);
	}
	if (ex->fd_out != -1 && ex->fd_out != STDOUT_FILENO)
	{
		dup2(ex->fd_out, STDOUT_FILENO);
		close(ex->fd_out);
	}
	else if (ex->fd_out == STDOUT_FILENO && tab[i + 1] != NULL)
	{
		dup2(pip[WRITE], STDOUT_FILENO);
	}
	else if (tab[i + 1] == NULL)
	{
		dup2(1, 1);
		//close(pip[READ]);
		dup2(0, 0);
	}
}

void	child_process(t_parstab tab, t_exec *ex, int i, int *pip)
{
	int		pid1;
	char	*path;
	char	**cmd;

	cmd = api_full_command(tab[i]);
	path = prep_path(cmd[0], ex->envp);
	if (is_a_builtin(cmd[0]) == 1)
	{
		redirect(tab, ex, i, pip);
		if (exec_builtin(cmd[0], tab, i) == FALSE)
			printf("paasss bon");
	}
	else
	{
		pid1 = fork();
		if (pid1 < 0)
			return ;
		if (pid1 == 0)
		{
			redirect(tab, ex, i, pip);
			if (execve(path, cmd, ex->envp) == -1)
			{
				printf("command not found : %s\n", cmd[0]);
				exit(0);
			}
		}
		else
		{
			close(pip[WRITE]);
			dup2(pip[READ], STDIN_FILENO);
			waitpid(pid1, NULL, 0);
		}
	}
}

void	exec_cmd(t_parstab tab, t_exec *ex, int i, int *pip)
{
	child_process(tab, ex, i, pip);
	//ex->fd_in = pip[READ];
	//close(pip[READ]);
	//waitpid(pid1, NULL, 0);
}
