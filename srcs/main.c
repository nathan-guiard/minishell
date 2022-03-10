/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 13:39:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char **command;
	char *path;
	int	res;
	
	catch_signals();
	while (1)
	{
		char *line = prompt();
		if (line)
		{
			command = ft_split(line, ' ');
			if (command[0])
			{
				free(line);
				path = exec_path(command[0]);
				res = builtin(command);
				if (res == FALSE || res == ERR)
				{
					res = exec_simple_command(command, env);
					if (res == FALSE || res == ERR)
						printf("%s: command not found\n", command[0]);
					free_tabtab(command);
				}
			}
		}
		else
			ft_exit_builtin(NULL);
	}
	return(0);
}
