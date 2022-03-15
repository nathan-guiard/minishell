/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 11:29:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char **argv, char **env)
{
	char	*line;
	char 	*test_l;

	(void)argc;
	(void)argv;
	(void)env;
	catch_signals();
	while (1)
	{
		line = prompt();
		if (line)
		{
			test_l = test(line);
			printf("%s\n", test_l);
		}
		else
			ft_exit_builtin(NULL);
	}
	return(0);
}
