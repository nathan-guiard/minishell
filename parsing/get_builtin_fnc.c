/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_builtin_fnc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 09:38:58 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 10:23:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	*get_fnc_tab(void);

/*	Renvoie une fonction "void(char **)" qui est un de nos builtin
	en fonction de cmd_name													*/
void *get_builtin_fnc(char *cmd_name)
{
	builtin_fnc *fnc_tab;
	char		**name_tab;
	int			i;

	name_tab = get_builtin_tab_name();
	fnc_tab = get_fnc_tab();
	i = 0;
	while (name_tab[i])
	{
		if (ft_strcmp(name_tab[i], cmd_name) == 0)
			return (fnc_tab[i]);
		i++;
	}
	return (NULL);
}

static void	*get_fnc_tab(void)
{
	builtin_fnc	*tab;

	tab = ft_calloc(sizeof(builtin_fnc), BUILTIN_NB + 1);
	tab[0] = echo;
	tab[1] = ft_exit_builtin;
	tab[2] = clear;
	tab[3] = cd;
	tab[4] = pwd;
	return (tab);
}