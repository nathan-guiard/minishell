/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 11:33:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	int i = 0;
	char **command;
	builtin_fnc	fnc;

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
			//add_history(line);
			command = ft_split(line, ' ');
			free(line);
			if (is_a_builtin(command[0]) != FALSE)
			{
				if (is_a_builtin(command[0]) == TRUE)
				{
					fnc = get_builtin_fnc(command[0]);
					command = remove_command_name(command);
					fnc(command);
				}
			}
			else
				printf("%s: command not found\n", command[0]);
			free_tabtab(command);
		}
		else
			ft_exit_builtin(NULL);
	}
	return(0);
}
