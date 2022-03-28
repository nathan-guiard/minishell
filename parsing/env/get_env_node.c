/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:59:14 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 14:53:28 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_node(char *name)
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
			return (free(cmp), tmp);
		free(cmp);
		tmp = tmp->next;
	}
	return (NULL);
}