/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rename_strings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 11:17:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 11:32:23 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_symbol get_redir_symbol(t_symbol symbol);
int				is_a_redirection(t_symbol symbol);

t_parstab	rename_strings(t_parstab tab)
{
	int			i;
	t_lexer		*buff;
	t_symbol	last;

	i = 0;
	while (tab[i])
	{
		buff = tab[i];
		last = -1;
		while (buff)
		{
			if (is_a_redirection(last) == TRUE && buff->symbol == string)
				buff->symbol = get_redir_symbol(last);
			last = buff->symbol;
			buff = buff->next;
		}
		i++;
	}
	return (tab);
}

int	is_a_redirection(t_symbol symbol)
{
	if (symbol == red_in
		|| symbol == red_out
		|| symbol == append
		|| symbol == heredoc)
		return (TRUE);
	return (FALSE);
}

static t_symbol	get_redir_symbol(t_symbol symbol)
{
	if (symbol == red_in)
		return (red_in_file);
	if (symbol == red_out)
		return (red_out_file);
	if (symbol == append)
		return (append_file);
	if (symbol == heredoc)
		return (delimiter);
	return (symbol);
}