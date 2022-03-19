/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:41:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 15:48:02 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Retourne la valeur de la variable name dans notre environnement
	Retourne NULL si la variable existe pas
	Meme comportement que getenv()									*/
char	*ft_getenv(char *name)
{
	int		ret;
	char	*env_line;

	ret = is_name_in_env(name);
	if (ret == FALSE)
		return (NULL);
	env_line = get_env_line(name);
	env_line = cut_env_name(env_line, name);
	return (env_line);
}

/*	Check si la variable name est dans env
	si elle y est,			return TRUE
	si elle y est pas,		return FALSE
	si g_env n'existe pas	return ERR		*/
int	is_name_in_env(char *name)
{
	t_list	*tmp;

	tmp = g_env;
	if (!tmp)
		return (ERR);
	while (tmp->next != NULL)
	{
		if (ft_strncmp(name, tmp->content, ft_strlen(name)) != 0)
			return (TRUE);
		tmp = tmp->next;
	}
	return (FALSE);
}

/*	Donne toute la ligne de env correspondant a name
	si elle y est,			return la ligne
	si elle y est pas ou
		que g_env n'existe
		pas:				return S_ERR				*/
char	*get_env_line(char *name)
{
	t_list	*tmp;

	tmp = g_env;
	if (!tmp)
		return (S_ERR);
	while (tmp->next != NULL)
	{
		if (ft_strncmp(name, tmp->content, ft_strlen(name)) != 0)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (S_ERR);
}

/*	Enleve le nom de la variable et le '=' qu'il y a devant
	Si erreur de malloc, retourne S_MERR					*/
char	*cut_env_name(char *env_line, char *name)
{
	char	*res;
	int		name_len;
	int		env_len;

	name_len = ft_strlen(name);
	env_len = ft_strlen(env_line) - name_len;
	res = ft_substr(env_line, name_len + 1, env_len);
	if (!res)
		return (S_MERR);
	return (res);
}