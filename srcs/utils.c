/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:33:46 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 16:20:28 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Free un tableau de tableaux */
void	free_tabtab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_parstab(t_parstab tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_lexerclear(&tab[i], free);
		i++;
	}
	free(tab);
}
