/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:09:13 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 14:50:18 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	unset(char **args)
{
	t_list	*node;
	int		i;

	i = 1;
	if (!args)
		return ;
	while (args[i])
	{
		node = get_env_node(args[i]);
		if (node)
			ft_lstpop(&g_env, node);
		i++;
	}
}
