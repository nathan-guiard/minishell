/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerlast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 11:41:50 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexerlast(t_lexer *lst)
{
	t_lexer	*buff;

	if (!lst)
		return (NULL);
	buff = lst;
	while (buff->next != NULL)
	{
		buff = buff->next;
	}
	return (buff);
}
