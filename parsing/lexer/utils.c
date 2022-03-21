/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:03:53 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 11:25:01 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	is_a_valid_pipe(char *line, int breakpoint)
{
	int		i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	if (line[breakpoint] != '|')
		return FALSE;
	while (line[i] != '\0' && i <= breakpoint)
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			if (line[i] == quote_type)
				quote_type = 0;
			else if (line[i] != quote_type && quote_type == 0)
				quote_type = line[i];
		}
		i++;
	}
	if (quote_type != 0)
		return (FALSE);
	return (TRUE);
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