/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerinsert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:49:47 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/22 13:12:38 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Insert la liset en ENTIER to_insert apres le maillon after_this_one
	de la liste alst													*/
void	ft_lexerinsert(t_lexer **alst, t_lexer *to_insert, t_lexer *after_this_one)
{
	t_lexer *buff;
	t_lexer	*following;

	if (!alst || !(*alst) || !after_this_one)
		return ;
	buff = *alst;
	while (buff)
	{
		if (buff == after_this_one)
		{
			following = buff->next;
			buff->next = to_insert;
			ft_lexerlast(to_insert)->next = following;
			break;
		}
		buff = buff->next;
	}
}