/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 08:20:22 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	int i = 0;
	char **command;

	catch_signals();
	//while (1)
	//{
	//	prompt();
	//}
	while (1)
	{
		char *line = prompt();
		if (line)
		{
			printf("ligne recue:%s\n", line);
			command = ft_split(line, ' ');
			if (ft_strcmp(command[0], "echo") == 0)
			{
				command = remove_command_name(command);
				echo(command);
			}
			else if (ft_strcmp(command[0], "cd") == 0)
			{
				command = remove_command_name(command);
				cd(command);
			}
			else if (ft_strcmp(command[0], "pwd") == 0)
			{
				command = remove_command_name(command);
				pwd(command);
			}
			else if (ft_strcmp(command[0], "exit") == 0)
			{
				command = remove_command_name(command);
				//reprendre ce que j'ai fait sur linux
				exit(command);
			}
			else if (ft_strcmp(command[0], "clear") == 0)
				clear();
			else
				printf("Command not found\n");
			free_tabtab(command);
		}
	}
	return(0);
}
