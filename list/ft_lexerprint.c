/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 10:54:04 by nguiard          ###   ########.fr       */
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
		if (buff->symbol == string)
		{
			printf("Content:%s\n", buff->content);
			printf("Symbol:%s\n\n", symbol_str);
		}
		else
			ft_printf("Symbol:\t%s\n\n", symbol_str);
		buff = buff->next;
		free(symbol_str);
	}
}