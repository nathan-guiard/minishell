/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerindex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:40:46 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 11:42:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Le miallon donne est le maillon numero 0,
**	si index est plus grand que la taille de
**	la liste, renvoie le dernier element	 */
t_lexer	*ft_lexerindex(t_lexer *lst, int index)
{
	t_lexer	*buff;
	int		i;

	i = 0;
	if (!lst)
		return (NULL);
	buff = lst;
	while (buff->next != NULL && i < index)
	{
		buff = buff->next;
		i++;
	}
	return (buff);
}
