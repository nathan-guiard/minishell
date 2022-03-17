/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 12:03:53 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 12:23:57 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_a_sep(char c)
{
	if (c == '\0' || c == '\n' || c == '\f'
		|| c == '\t' || c == '\r' || c == '\v'
		|| c == ' ' || c == '|')
		return (TRUE);
	return (FALSE);
}

int	get_lexer_len(char *line, int i)
{
	int	len;

	len = i;
	while (is_a_sep(line[len]) == FALSE)
		len++;
	return (len - i);
}