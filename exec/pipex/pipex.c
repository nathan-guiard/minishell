/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:49:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/02 11:43:35 by nguiard          ###   ########.fr       */
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
		while (tab[i] != NULL)
		{
			set_layout_printf(C_GREEN, C_RESET, C_RESET);
			printf("Pipe nb %d, taille de la liste: %d \n", i, ft_lexersize(tab[i]));
			set_layout(C_BLUE, C_RESET, C_ITALIC);
			set_layout(C_BLUE, C_RESET, C_BOLD);
			ft_lexerprint(tab[i]);
			set_layout_printf(C_RESET, C_RESET, C_RESET);
			set_layout_printf(C_HYELLOW, C_RESET, C_ITALIC);
			int j = 0;
			char **truc = api_full_command(tab[i]);
			while (truc && truc[j])
			{
				printf("%s\n", truc[j]);
				j++;
			}
			if (truc)
				free_tabtab(truc);
			i++;
		}
		i = 0;
		free_parstab(tab);
	}
}