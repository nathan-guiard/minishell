/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_get_symbin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 19:28:07 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/13 16:28:41 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_symbol	api_get_symbin(t_lexer *list)
{
	t_lexer		*buff;
	t_symbol	symb;

	buff = list;
	while (buff)
	{
		if ((buff->symbol == red_in || buff->symbol == heredoc) && buff->next)
			symb = buff->symbol;
		buff = buff->next;
	}
	return (symb);
}
