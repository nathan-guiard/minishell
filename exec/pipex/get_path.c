/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:03:04 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/13 18:22:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_strjoin_path(char const *s1, char const *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	i = 0;
	if (*s1 == '\0' || *s2 == '\0')
		return (NULL);
	res = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '/';
	i++;
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

static void	free_path_tab(char **path_tab)
{
	int	i;

	i = 0;
	while (path_tab[i])
	{
		free(path_tab[i]);
		i++;
	}
	free(path_tab);
}

static int	get_right_index(char *envp[])
{
	int	index;

	index = 0;
	while (envp[index])
	{
		if (ft_strncmp(envp[index], "PATH=", 4) == 0)
			return (index);
		index++;
	}
	return (-1);
}

char	*prep_path(char *cmd, char**envp)
{
	int		i;
	char	**path_tab;
	char	*path;

	if (!cmd)
		return (NULL);
	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	i = get_right_index(envp);
	if (i == -1)
		return (NULL);
	path_tab = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path_tab[i] != NULL)
	{
		path = ft_strjoin_path(path_tab[i], cmd);
		if (access(path, X_OK) == 0)
		{
			free_path_tab(path_tab);
			return (path);
		}
		free(path);
		i++;
	}
	if (path_tab)
		free_path_tab(path_tab);
	return (NULL);
}
