/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:49:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 12:59:36 by nguiard          ###   ########.fr       */
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
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		set_layout_printf(C_GREEN, C_RESET, C_RESET);
		printf("Pipe nb %d, taille de la liste: %d \n",
			i, ft_lexersize(tab[i]));
		set_layout(C_BLUE, C_RESET, C_ITALIC);
		set_layout(C_BLUE, C_RESET, C_BOLD);
		ft_lexerprint(tab[i]);
		set_layout_printf(C_RESET, C_RESET, C_RESET);
		i++;
	}
	free_parstab(tab);
}