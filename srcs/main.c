/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 10:01:54 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *g_env;

int main(int argc, char **argv, char **env)
{
	char		*line;
	t_parstab	tab;
	int			i;

	(void)argc;
	(void)argv;
	(void)env;

	//catch_signals();
	i = 0;
	while (1)
	{
		line = prompt();
		if (line)
		{
			//printf("%d\n", symbol_change(line, 0));
			tab = full_parsing(line);
			printf("%p\n", tab);
			if (tab == NULL)
				ft_putstr_fd("Syntax error.\n", 2);
			else
			{
				set_layout_printf(C_HGREN, C_RESET, C_ITALIC);
				printf("tab[%d] = %p\n", i, tab[i]);
				while (tab[i] != NULL)
				{
					set_layout_printf(C_GREEN, C_RESET, C_RESET);
					printf("Pipe nb %d\n", i);
					set_layout_printf(C_HGREN, C_RESET, C_ITALIC);
					ft_lexerprint(tab[i]);
					i++;
				}
				i = 0;
				while (tab[i])
				{
					ft_lexerclear(&tab[i], free);
					i++;
				}
				free(tab);
			}
			i = 0;
		}
		else
			break;
	}
	ft_exit_builtin(NULL);
	return(0);
}