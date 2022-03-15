/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_turn_env_into_list.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:33:47 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 13:41:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	turn_env_into_list(char **env)
{
	int	i;
	t_list	*node;

	i = 1;
	node = ft_lstnew(env[0]);
	while (env[i])
	{
		ft_lstadd_back(&node, ft_lstnew(env[i]));
		i++;
	}
	g_env = node;
}