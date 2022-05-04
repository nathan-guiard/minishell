/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_command_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:36:24 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 11:16:44 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Enleve le premier element d'un tableau de
	tableaux, et free le tableau de base. 
	Dans notre cas le premier element c'est la
	commande									*/
char	**remove_command_name(char **args)
{
	char	**res;
	int		len;
	int		i;

	len = 0;
	i = 1;
	while (args[len])
		len++;
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), NULL);
	while (args[i])
	{
		res[i - 1] = ft_strdup(args[i]);
		i++;
	}
	res[i] = NULL;
	free_tabtab(args);
	return (res);
}
