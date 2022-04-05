/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 17:18:24 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *g_env = NULL;

int main(int argc, char **argv, char **env)
{
	char		*line;
	t_parstab	tab;
	//char **dtab;
	
	(void)argc;
	(void)argv;

	catch_signals();
	turn_env_into_list(env);
	set_ret_value(0);
	while (1)
	{
		line = prompt();
		if (line)
		{
			if (line[0] != '\0')
			{	
				tab = full_parsing(line);
				//add_history(ft_strdup(line));
				pipex(tab);
			}
			else
				free(line);
		}
		else
			break;
	}
	ft_exit_builtin(NULL);
	return(0);
}