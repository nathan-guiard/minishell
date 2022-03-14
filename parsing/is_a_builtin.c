/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:48:34 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/14 13:22:16 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Permet de savoir si la commande est un built-in de notre shell
	ou si c'est autre chose, voici la liste des builtins geres pour
	l'instant:
	echo		exit		pwd
	clear		cd																*/
int		is_a_builtin(char *cmd_name)
{
	int i;
	char **builtin_tab_name;

	i = 0;
	if (!cmd_name)
		return (FALSE);
	builtin_tab_name = get_builtin_tab_name();
	if (!builtin_tab_name)
		return (ft_putstr_fd("malloc() error", 2), ERR);
	while (builtin_tab_name[i])
	{
		if (ft_strcmp(builtin_tab_name[i], cmd_name) == 0)
			return (free_tabtab(builtin_tab_name), TRUE);
		i++;
	}
	return (free_tabtab(builtin_tab_name), FALSE);
}

/*	Retourne un tableau de tableau avec tous les noms de builtin				*/
char **get_builtin_tab_name(void)
{
	char **builtin_tab;
	int i;

	i = 0;
	builtin_tab =malloc(sizeof(char *) * (BUILTIN_NB + 1));
	builtin_tab[0] = ft_strdup("echo");
	if (!builtin_tab[0])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[1] = ft_strdup("exit");
	if (!builtin_tab[1])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[2] = ft_strdup("clear");
	if (!builtin_tab[2])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[3] = ft_strdup("cd");
	if (!builtin_tab[3])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[4] = ft_strdup("pwd");
	if (!builtin_tab[4])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[5] = ft_strdup("env");
	if (!builtin_tab[5])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[6] = ft_strdup("export");
	if (!builtin_tab[6])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[7] = ft_strdup("unset");
	if (!builtin_tab[7])
		return (free_tabtab(builtin_tab), NULL);
	builtin_tab[BUILTIN_NB] = NULL;
	return (builtin_tab);
}