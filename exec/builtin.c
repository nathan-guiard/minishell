/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:45:05 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/12 16:36:35 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(char **command)
{
	t_builtin_fnc	fnc;

	if (is_a_builtin(command[0]) != FALSE)
	{
		if (is_a_builtin(command[0]) == TRUE)
		{
			fnc = get_builtin_fnc(command[0]);
			command = remove_command_name(command);
			fnc(command);
			free_tabtab(command);
			return (TRUE);
		}
		return (ERR);
	}
	else
		return (FALSE);
}

void	redirect_built_alone(t_exec *ex)
{
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
}

void	closefd_builts_alone(t_exec *ex)
{
	if (ex->fd_in > STDIN_FILENO)
		close(ex->fd_in);
	if (ex->fd_out > STDOUT_FILENO)
		close(1);
}

void	exec_builtin_alone(char *cmd, t_parstab tab, int i, char **env)
{
	t_exec	ex;

	ex = init_struct_exec(tab[i], env);
	redirect_built_alone(&ex);
	exec_builtin(cmd, tab, i);
	closefd_builts_alone(&ex);
}
