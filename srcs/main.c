/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/09 17:48:10 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	int i = 0;
	char **command;

	while (1)
	{
		command = ft_split(prompt(), ' ');
		if (command)
		{
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
			else
				printf("Command not found\n");
			free_tabtab(command);
		}
	}
	return(0);
}
