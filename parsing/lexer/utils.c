/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:03:53 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:28:14 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*first_test(t_symbol symbol);

int	is_a_sep(char c)
{
	if (c == '\n' || c == '\f'
		|| c == '\t' || c == '\r' || c == '\v'
		|| c == ' ' || c == '|')
		return (TRUE);
	return (FALSE);
}

int	get_lexer_len(char *line, int i)
{
	int	len;

	len = i;
	while (is_a_sep(line[len]) == FALSE && line[len] != '\0')
		len++;
	return (len - i);
}

/*	Check si le symbole est un separateur dans une string, genre
	echo|ls le pipe "separe" la commande							*/
int	is_a_symbol_sep(t_symbol symbol)
{
	if (symbol == red_in
		|| symbol == red_out
		|| symbol == append
		|| symbol == heredoc
		|| symbol == quote
		|| symbol == d_quote
		|| symbol == sb_pipe)
		return (TRUE);
	return (FALSE);
}

/*	A supprimer a la fin puisque c que du testing	*/
char	*translate_symbol(t_symbol symbol)
{
	char	*test;

	test = first_test(symbol);
	if (test)
		return (test);
	if (symbol == quote)
		return (ft_strdup("quote"));
	if (symbol == sb_pipe)
		return (ft_strdup("sb_pipe"));
	if (symbol == delimiter)
		return (ft_strdup("delimiter"));
	if (symbol == red_in_file)
		return (ft_strdup("red_in_file"));
	if (symbol == red_out_file)
		return (ft_strdup("red_out_file"));
	if (symbol == append_file)
		return (ft_strdup("append_file"));
	if (symbol == nothing)
		return (ft_strdup("nothing"));
	return (ft_strdup("symbol not found"));
}

char	*first_test(t_symbol symbol)
{
	if (symbol == string)
		return (ft_strdup("string"));
	if (symbol == red_in)
		return (ft_strdup("red_in"));
	if (symbol == red_out)
		return (ft_strdup("red_out"));
	if (symbol == append)
		return (ft_strdup("append"));
	if (symbol == heredoc)
		return (ft_strdup("heredoc"));
	if (symbol == path)
		return (ft_strdup("path"));
	if (symbol == command)
		return (ft_strdup("command"));
	if (symbol == sb_builtin)
		return (ft_strdup("sb_builtin"));
	if (symbol == argument)
		return (ft_strdup("argument"));
	if (symbol == d_quote)
		return (ft_strdup("d_quote"));
	return (NULL);
}
