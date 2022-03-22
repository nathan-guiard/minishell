/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/22 13:20:11 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexerclear(t_lexer **lst, void (*del)(void *))
{
	t_lexer	*buff;
	t_lexer	*tmp;

	if (!*lst)
		return ;
	buff = *lst;
	while (buff->next != NULL)
	{
		tmp = buff->next;
		ft_lexerdelone(buff, del);
		buff = tmp;
	}
	ft_lexerdelone(buff, del);
	*lst = NULL;
}
