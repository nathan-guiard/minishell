/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:59:14 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:20:36 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_node(char *name)
{
	t_list	*tmp;

	tmp = g_env;
	if (!tmp)
		return (ERR);
	while (tmp->next != NULL)
	{
		if (ft_strncmp(name, tmp->content, ft_strlen(name)) != 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
