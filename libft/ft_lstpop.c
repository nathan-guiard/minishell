/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:08 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/16 17:20:12 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpop(t_list **alst, t_list *node)
{
	t_list	*following;
	t_list	*buff;

	if (!alst || !(node->content) || !node)
		return ;
	if (node->next == NULL)
		return (ft_lstdelone(node, free));
	buff = *alst;
	while (buff->next != NULL)
	{
		if (buff == node)
		{
			following = node->next;
			ft_lstdelone(node, free);
			ft_lstadd_back(alst, following);
			break;
		}
		buff = buff->next;
	}
}
