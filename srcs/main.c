/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 09:59:24 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env = NULL;
static void	the_loop(void);

int	main(int argc, char **argv, char **env)
{
	(void)argv;
	(void)argc;
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
				if (tab)
					pipex(tab);
			}
			else
				free(line);
		}
		else
			break ;
	}
}
