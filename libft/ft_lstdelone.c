/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:08 by nguiard           #+#    #+#             */
/*   Updated: 2022/02/02 10:01:57 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !(lst->content))
		return ;
	(*del)(lst->content);
	free(lst);
}

void	ft_lstdelone_int(t_list_int *lst)
{
	if (!lst)
		return ;
	free(lst);
}
