/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:49:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 17:40:25 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mon_pipex_eclate(t_parstab parsing);

//	a remplacer par le vrai pipex
void	pipex(t_parstab	parsing)
{
	mon_pipex_eclate(parsing);
}

//	pour faire mes tests
void	mon_pipex_eclate(t_parstab tab)
{
	int i = 0;

	printf("%p\n", tab);
	if (tab == NULL)
		ft_putstr_fd("Syntax error.\n", 2);
	else
	{
		set_layout_printf(C_HRED, C_RESET, C_ITALIC);
		printf("tab[%d] = %p\n", i, tab[i]);
		while (tab[i] != NULL)
		{
			set_layout_printf(C_GREEN, C_RESET, C_RESET);
			printf("Pipe nb %d, taille de la liste: %d \n", i, ft_lexersize(tab[i]));
			set_layout(C_BLUE, C_RESET, C_ITALIC);
			set_layout(C_BLUE, C_RESET, C_BOLD);
			ft_lexerprint(tab[i]);
			
			set_layout_printf(C_RESET, C_RESET, C_RESET);
			set_layout_printf(C_HYELLOW, C_RESET, C_ITALIC);
			printf("last red_in: %s\n", api_last_red_in(tab[i]));
			printf("last red_out: %s\n", api_last_red_out(tab[i]));
			
			int j = 0;
			t_doubletab test = api_get_command_tab(tab[i]);
			printf("Tab de tab:\n\n");
			while (test[j])
			{
				printf("Content: %s (%ld) [%d]\n", test[j], ft_strlen(test[j]), test[j][0]);
				j++;
			}
			char **merde;
			j = 0;
			printf("every red_out:\n");
			merde = api_every_red_out(tab[i]);
			while (merde[j])
			{
				printf("%s\n", merde[j]);
				j++;
			}
			printf("[[%s]]\n", api_heredoc_delimiter(tab[i]));
			free_tabtab(merde);
			free_tabtab(test);
			i++;
		}
		i = 0;
		free_parstab(tab);
	}
}