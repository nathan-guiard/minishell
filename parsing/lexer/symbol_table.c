/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_table.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:04:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 15:23:34 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer		*get_symbol_table(char *line, int *i);

char	*test(char *line)
{
	int	i;

	i = 0;
	return (get_lexer_content(line, &i));
}

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

t_lexer	*get_symbol_table(char *line, int *i)
{
	char		*content;
	t_symbol	symbol;
	t_lexer		*res;
	t_lexer		*node;

	while (line[*i] != '\0' && is_a_valid_pipe(line, *i) != TRUE)
	{
		content	= get_lexer_content(line, i);
		symbol = get_symbol(content);
		node = ft_lexernew(content, symbol);
		ft_lexeradd_back(&res, node);
	}
	return (res);
}

char	*get_lexer_content(char *line, int *i)
{
	char	*res;
	int		j;

	while (is_a_sep(line[*i]) == TRUE)
		*i = *i + 1;
	j = *i;
	res = malloc(sizeof(char) * (get_lexer_len(line, *i) + 1));
	while (is_a_sep(line[*i]) == FALSE)
	{
		res[*i - j] = line[*i];
		*i = *i + 1;
	}
	res[*i - j] = '\0';
	return (res);
}