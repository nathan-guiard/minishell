/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_env_into_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:33:47 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 11:58:31 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	turn_env_into_list(char **env)
{
	int		i;
	t_list	*node;

	i = 1;
	if (!env || !env[0])
	{
		g_env = NULL;
		return ;
	}
	node = ft_lstnew(ft_strdup(env[0]));
	while (env[i])
	{
		ft_lstadd_back(&node, ft_lstnew(ft_strdup(env[i])));
		i++;
	}
	g_env = node;
}
