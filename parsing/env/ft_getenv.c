/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:41:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 17:16:55 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_name_in_env(char *name);
char	*get_env_line(char *name);
char	*cut_env_name(char *line);

/*	Retourne la valeur de la variable name dans notre environnement
	Retourne NULL si la variable existe pas
	Meme comportement que getenv()
	A FREE															*/
char	*ft_getenv(char *name)
{
	int		ret;
	char	*env_line;

	if (!name || name[0] == '\0')
		return (NULL);
	ret = is_name_in_env(name);
	if (ret == FALSE)
		return (NULL);
	env_line = get_env_line(name);
	if (!env_line)
		return (NULL);
	env_line = cut_env_name(env_line);
	return (env_line);
}

int	is_name_in_env(char *name)
{
	t_list	*tmp;
	char	*to_cmp;

	tmp = g_env;
	if (!tmp)
		return (ERR);
	while (tmp)
	{
		to_cmp = tmp->content;
		if (ft_strncmp(name, to_cmp, ft_strlen(name)) == 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

char	*get_env_line(char *name)
{
	t_list	*tmp;
	char	*cmp;

	tmp = g_env;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		cmp = ft_substr((char *)tmp->content, 0, ft_strlen(name));
		if (ft_strcmp(name, cmp) == 0)
			return (free(cmp), ft_strdup(tmp->content));
		free(cmp);
		tmp = tmp->next;
	}
	return (NULL);
}

char	*cut_env_name(char *line)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i])
	{
		if (line[i] == '=')
		{
			i++;
			break ;
		}
		i++;
	}
	res = ft_substr(line, i, INT_MAX);
	free(line);
	return (res);
}
