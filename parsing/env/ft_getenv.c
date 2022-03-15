/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:41:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 14:01:15 by nguiard          ###   ########.fr       */
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
	env_line = cut_env_name(env_line);
	return (env_line);
}

int	is_name_in_env(name)
{
	t_list	*tmp;

	tmp = g_env;
	if (!tmp)
		return (ERR);
	while (tmp->next != NULL)
	{
		if (ft_strncmp(name, tmp->content, ft_strlen(name)) != 0)
			return (TRUE);
		tmp = tmp->tmp;
	}
	return (TRUE);
}