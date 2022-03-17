/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:04:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 11:35:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list	*symbol_table_list(char *line)
{
	t_list		*res;
	t_list		*node;
	t_lexer	*symbol_table;
	int		i;

	i = 0;
	symbol_table = get_symbol_table(line, &i);
	while (symbol_table != NULL)
	{
		node = ft_lstnew(symbol_table);
		ft_lstadd_back(&res, node);
		symbol_table = get_symbol_table(line, &i);
	}
	return (res);
}

t_lexer	get_symbol_table(char *line, int *i)
{
	char		*content;
	t_symbol	symbol;
	t_lexer		*res;
	t_lexer		*node;

	while (line[*i] != '\0' || line[*i] != '|')
	{
		content	= get_lexer_content(line, *i);
		symbol = get_symbol(content);
		node = ft_lexer_new(content, t_symbol);
		ft_lexeradd_back(&res, node);
		*i = *i + 1;
	}
}