/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/16 18:11:27 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*g_env;

int main(int argc, char **argv, char **env)
{
	//char	*line;
	//char 	*test_l;

	(void)argc;
	(void)argv;
	(void)env;

	turn_env_into_list(env);
	ft_env(NULL);
	set_layout_printf(C_HGREN, C_RESET, C_RESET);
	ft_env(NULL);
	//char **tab = get
	//catch_signals();
	//while (1)
	//{
	//	line = prompt();
	//	if (line)
	//	{
	//		test_l = replace_variables(line);
	//		set_layout_printf(C_GREEN, C_RESET, C_BOLD);
	//		printf("Retour test: %s\n", test_l);
	//		set_layout_printf(C_RESET, C_RESET, C_RESET);
	//		free(test_l);
	//	}
	//	else
	//		ft_exit_builtin(NULL);
	//}
	return(0);
}
