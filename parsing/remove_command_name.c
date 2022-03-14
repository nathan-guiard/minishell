/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_command_name.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:36:24 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/14 13:22:34 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Enleve le premier element d'un tableau de
	tableaux, et free le tableau de base. 
	Dans notre cas le premier element c'est la
	commande									*/
char **remove_command_name(char **args)
{
	char **res;
	int	len;
	int i;

	len = 0;
	i = 1;
	while (args[len])
		len++;
	res = malloc(sizeof(char *) * (len + 1));
	while (args[i])
	{
		res[i - 1] = ft_strdup(args[i]);
		i++;
	}
	res[i] = NULL;
	free_tabtab(args);
	return (res);
}