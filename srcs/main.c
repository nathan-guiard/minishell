/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 12:25:51 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *g_env = NULL;

int main(int argc, char **argv, char **env)
{
	char		*line;
	//t_parstab	tab;
	//int			i = 0;
	char **dtab;
	
	(void)argc;
	(void)argv;

	catch_signals();
	turn_env_into_list(env);
	while (1)
	{
		line = prompt();
		if (line)
		{
			if (line[0] != '\0')
			{
				dtab =  ft_split(line, ' ');
				if (ft_strcmp(dtab[0], "unset") == 0)
					unset(dtab);
				else if (ft_strcmp(dtab[0], "env") == 0)
					ft_env(NULL);
				else if (ft_strcmp(dtab[0], "export") == 0)
					export(dtab);
				free_tabtab(dtab);
				free(line);
				
				
				//tab = full_parsing(line);
				//printf("%p\n", tab);
				//if (tab == NULL)
				//	ft_putstr_fd("Syntax error.\n", 2);
				//else
				//{
				//	set_layout_printf(C_HRED, C_RESET, C_ITALIC);
				//	printf("tab[%d] = %p\n", i, tab[i]);
				//	while (tab[i] != NULL)
				//	{
				//		set_layout_printf(C_GREEN, C_RESET, C_RESET);
				//		printf("Pipe nb %d, taille de la liste: %d \n", i, ft_lexersize(tab[i]));
				//		set_layout(C_BLUE, C_RESET, C_ITALIC);
				//		set_layout(C_BLUE, C_RESET, C_BOLD);
				//		ft_lexerprint(tab[i]);
						
				//		set_layout_printf(C_RESET, C_RESET, C_RESET);
				//		set_layout_printf(C_HYELLOW, C_RESET, C_ITALIC);
				//		printf("last red_in: %s\n", api_last_red_in(tab[i]));
				//		printf("last red_out: %s\n", api_last_red_out(tab[i]));
						
				//		int j = 0;
				//		t_doubletab test = api_get_command_tab(tab[i]);
				//		printf("Tab de tab:\n\n");
				//		while (test[j])
				//		{
				//			printf("Content: %s (%ld) [%d]\n", test[j], ft_strlen(test[j]), test[j][0]);
				//			j++;
				//		}
				//		free_tabtab(test);
				//		i++;
				//	}
				//	i = 0;
				//	free_parstab(tab);
				//}
				//i = 0;
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