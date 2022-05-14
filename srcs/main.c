/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 16:48:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list		*g_env = NULL;
static void	pars_and_pipe(char *line);
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

	while (42)
	{
		line = prompt();
		if (line)
		{
			if (line[0] != '\0')
				pars_and_pipe(line);
			else
				free(line);
		}
		else
			break ;
	}
}

static void	pars_and_pipe(char *line)
{
	t_parstab	tab;
	char		**env;

	add_history(line);
	tab = full_parsing(line);
	if (tab)
	{
		env = turn_env_into_tab();
		pipex(tab, env);
		free_parstab(tab);
		free_tabtab(env);
	}
	else
		set_ret_value(2);
}
