/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:00:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 12:23:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Renvoie le path vers l'executable correspondant a cmd_name
	Si cmd_name n'existe dans aucun path, retourne NULL			*/
char	*exec_path(char *cmd_name)
{
	char	**path_tab;
	char	*full_path;
	char	*cmd_name_with_slash;
	int		i;

	i = 0;
	path_tab = ft_split(getenv("PATH"), ':');
	if (!path_tab)
		return (S_ERR);
	while (path_tab[i])
	{
		cmd_name_with_slash = ft_strjoin("/", cmd_name);
		full_path = ft_strjoin(path_tab[i], cmd_name_with_slash);
		if (access(full_path, X_OK) == 0)
			return (free_tabtab(path_tab), full_path);
		free(full_path);
		free(cmd_name_with_slash);
		i++;
	}
	free_tabtab(path_tab);
	return (NULL);
}
