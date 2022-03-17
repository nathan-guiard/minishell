/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:08 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 11:42:34 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexerdelone(t_lexer *lst, void (*del)(void *))
{
	if (!lst || !(lst->content))
		return ;
	(*del)(lst->content);
	free(lst);
}
