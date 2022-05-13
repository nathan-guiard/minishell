/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_a_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 08:48:34 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 16:32:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Permet de savoir si la commande est un built-in de notre shell
	ou si c'est autre chose, voici la liste des builtins geres pour
	l'instant:
	echo		exit		pwd
	clear		cd													*/
int	is_a_builtin(char *cmd_name)
{
	int		i;
	char	**builtin_tab_name;

	i = 0;
	if (!cmd_name)
		return (FALSE);
	builtin_tab_name = get_builtin_tab_name();
	if (!builtin_tab_name)
		return (ft_putstr_fd(MERR_STR, 2), FALSE);
	while (builtin_tab_name[i])
	{
		if (ft_strcmp(builtin_tab_name[i], cmd_name) == 0)
			return (free_tabtab(builtin_tab_name), TRUE);
		i++;
	}
	return (free_tabtab(builtin_tab_name), FALSE);
}

/*	Retourne un tableau de tableau avec tous les noms de builtin	*/
char	**get_builtin_tab_name(void)
{
	char	**builtin_tab;

	builtin_tab = malloc(sizeof(char *) * (BUILTIN_NB + 1));
	if (!builtin_tab)
		return (NULL);
	builtin_tab[0] = ft_strdup("echo");
	builtin_tab[1] = ft_strdup("exit");
	builtin_tab[2] = ft_strdup("cd");
	builtin_tab[3] = ft_strdup("pwd");
	builtin_tab[4] = ft_strdup("env");
	builtin_tab[5] = ft_strdup("export");
	builtin_tab[6] = ft_strdup("unset");
	builtin_tab[BUILTIN_NB] = NULL;
	return (builtin_tab);
}
