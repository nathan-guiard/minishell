/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:00:32 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 11:12:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_simple_command(char **command, char **env)
{
	char	*path;
	pid_t	pid;

	path = exec_path(command[0]);
	if (!path)
		return (FALSE);
	pid = fork();
	if (pid == 0)
		execve(path, command, env);
	waitpid(pid, NULL, 0);
	return (TRUE);
}
