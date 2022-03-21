/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:57:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 13:35:34 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Change les parties quoted en un seul maillon quoted_string
	Les maillons quoted_string sont a prendre tels quel et a
	ne surtout pas changer le contenu							*/
void	quote_handling(t_lexer **list)
{
	t_lexer	*buff;

	if (!list)
		return ;
	buff = *list;
	while (buff)
	{
		neutralize_the_quote(buff);
		buff = buff->next;
	}
}