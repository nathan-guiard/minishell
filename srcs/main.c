/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 12:19:49 by nguiard          ###   ########.fr       */
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
			if (line[0] != '\0')
			{
				tab = full_parsing(line);
				//printf("%p\n", tab);
				if (tab == NULL)
					ft_putstr_fd("Syntax error.\n", 2);
				else
				{
					set_layout_printf(C_HRED, C_RESET, C_ITALIC);
					printf("tab[%d] = %p\n", i, tab[i]);
					while (tab[i] != NULL)
					{
						set_layout_printf(C_GREEN, C_RESET, C_RESET);
						printf("Pipe nb %d\n", i);
						set_layout_printf(C_BLUE, C_RESET, C_ITALIC);
						set_layout_printf(C_BLUE, C_RESET, C_BOLD);
						ft_lexerprint(tab[i]);
						
						printf("last: %s\n", api_last_red_out(tab[i]));
						i++;
					}
					i = 0;
					free_parstab(tab);
				}
				i = 0;
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