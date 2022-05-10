/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/10 20:43:11 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env = NULL;
static void	the_loop(char **env);

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
	catch_signals();
	turn_env_into_list(env);
	set_ret_value(0);
	the_loop(env);
	ft_exit_builtin(NULL);
	return (0);
}

static void	the_loop(char **env)
{
	char		*line;
	t_parstab	tab;

	(void)env;
	while (1)
	{
		line = prompt();
		if (line)
		{
			if (line[0] != '\0')
			{	
				add_history(line);
				tab = full_parsing(line);
				if (tab)
					pipex(tab, env);
				free_parstab(tab);
			}
			else
				free(line);
		}
		else
			break ;
	}
}
