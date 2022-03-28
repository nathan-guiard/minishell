/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerprint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 09:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:19:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_writable(t_symbol symbol);

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
		if (is_writable(buff->symbol) == TRUE)
		{
			ft_printf("Content:%s\n", buff->content);
			ft_printf("Symbol:%s\n\n", symbol_str);
		}
		else
			ft_printf("Symbol:\t%s\n\n", symbol_str);
		buff = buff->next;
		free(symbol_str);
	}
}

int	is_writable(t_symbol symbol)
{
	if (symbol == string || symbol == path
		|| symbol == sb_builtin || symbol == argument
		|| symbol == variable || symbol == delimiter
		|| symbol == red_in_file || symbol == red_out_file
		|| symbol == append_file || symbol == command)
		return (TRUE);
	return (FALSE);
}
