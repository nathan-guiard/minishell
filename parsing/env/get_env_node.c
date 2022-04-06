/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 09:59:14 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:19:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*get_env_node(char *name)
{
	t_list	*tmp;
	char	*cmp;
	char	*with_equal;

	tmp = g_env;
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		with_equal = ft_strjoin(tmp->content, "=");
		cmp = ft_substr(with_equal, 0, ft_strlen(with_equal));
		if (ft_strcmp(name, cmp) == -61)
			return (free(cmp), free(with_equal), tmp);
		free(cmp);
		free(with_equal);
		tmp = tmp->next;
	}
	return (NULL);
}
