/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 16:48:58 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/14 18:33:29 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	open_files(t_symbol sb, t_lexer *ls)
{
	int	file;

	file = 0;
	if (sb == red_in)
		file = open(ls->next->content, O_RDONLY, 0644);
	else if (sb == red_out)
		file = open(ls->next->content, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (sb == append)
		file = open(ls->next->content, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else
		return (file);
	return (file);
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
}

void	parent_proc(int *pip)
{
	close(pip[WRITE]);
	dup2(pip[READ], STDIN_FILENO);
	close(pip[READ]);
}

void	child_process(t_parstab tab, t_exec *ex, int i, int *pip)
{
	int		pid1;
	char	*path;
	char	**cmd;

	cmd = api_full_command(tab[i]);
	path = prep_path(cmd[0], ex->envp);
	end_signals();
	pid1 = fork();
	if (pid1 == 0)
	{
		restore_default_sig();
		if (is_a_builtin(cmd[0]) == 1)
			exec_builtin_pipe(ex, i, tab, pip);
		else
		{
			redirect(tab, ex, i, pip);
			if (execve(path, cmd, ex->envp) == -1)
				cmd_nf(cmd[0]);
		}
	}
	else
		parent_proc(pip);
	free_tabtab(cmd);
	free(path);
}

void	exec_cmd(t_parstab tab, t_exec *ex, int i, int *pip)
{
	char	*cmd;

	if (ex->fd_in == -2)
	{
		heredoc_par(tab, i);
	}
	cmd = api_command_name(tab[i]);
	if (cmd != NULL)
		child_process(tab, ex, i, pip);
}
