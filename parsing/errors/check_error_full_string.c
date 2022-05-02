/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error_full_string.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 10:04:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/02 14:53:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_an_invalid_ender(t_symbol symbol);

/*	Check si il y a des erreurs dans la string en entiere
	(pas dans les pipes separees)
	retourne TRUE si erreur il y a et FALSE otherwise		*/
int	check_error_full_string(t_lexer *list)
{
	t_lexer	*buff;

	if (!list)
		return (TRUE);
	buff = list;
	if (buff->symbol == sb_pipe)
		return (TRUE);
	while (buff->next)
	{
		if ((is_a_symbol_sep(buff->symbol) == TRUE && buff->symbol != sb_pipe)
			&& is_a_symbol_sep(buff->next->symbol) == TRUE)
			return (TRUE);
		buff = buff->next;
	}
	if (is_an_invalid_ender(ft_lexerlast(list)->symbol) == TRUE)
		return (TRUE);
	return (FALSE);
}

int	is_an_invalid_ender(t_symbol symbol)
{
	if (symbol == red_in
		|| symbol == red_out
		|| symbol == heredoc
		|| symbol == append
		|| symbol == sb_pipe)
		return (TRUE);
	return (FALSE);
}
