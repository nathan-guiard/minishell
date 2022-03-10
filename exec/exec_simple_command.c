/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_simple_command.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:00:32 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 13:15:24 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_simple_command(char **command, char **env)
{
	char	*path;
	char	**args;

	path = exec_path(command[0]);
	if (!path)
		return (FALSE);
	if (ft_strcmp(path, S_ERR) == 0)
		return (ERR);
	execve(path, command, env);
	printf("Yeet\n");
	return (TRUE);
}