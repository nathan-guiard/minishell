/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_get_symb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 21:42:50 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/10 22:09:04 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_symbol	api_get_symb(t_lexer *list)
{
	t_lexer		*buff;
	t_symbol	symb;

	buff = list;
	while (buff)
	{
		if ((buff->symbol == red_out || buff->symbol == append) && buff->next)
			symb = buff->symbol;
		buff = buff->next;
	}
	return (symb);
}
