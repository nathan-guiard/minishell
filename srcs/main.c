/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:27:11 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env = NULL;
static void	the_loop(void);

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	if (argc != 1)
	{
		set_layout(C_RED, C_RESET, C_BOLD);
		ft_putendl_fd("Your arguments won't do anything", 2);
		set_layout(C_RESET, C_RESET, C_RESET);
	}
	catch_signals();
	turn_env_into_list(env);
	set_ret_value(0);
	the_loop();
	ft_exit_builtin(NULL);
	return (0);
}

static void	the_loop(void)
{
	char		*line;
	t_parstab	tab;

	while (1)
	{
		line = prompt();
		if (line)
		{
			if (line[0] != '\0')
			{	
				add_history(line);
				tab = full_parsing(line);
				pipex(tab);
			}
			else
				free(line);
		}
		else
			break ;
	}
}
