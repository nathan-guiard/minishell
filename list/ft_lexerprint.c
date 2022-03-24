/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 09:24:16 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexerprint(t_lexer *lst)
{
	t_lexer	*buff;
	char	*symbol_str;

	if (!lst)
	{
		ft_printf("La liste est vide\n");
		return ;
	}
	buff = lst;
	while (buff)
	{
		symbol_str = translate_symbol(buff->symbol);
		ft_printf("Content:%s\nSymbol:%s\n\n", buff->content, symbol_str);
		buff = buff->next;
		free(symbol_str);
	}
}