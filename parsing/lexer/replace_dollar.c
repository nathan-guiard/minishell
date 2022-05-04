/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:03:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 14:23:57 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			is_a_delimiter(char *line, int breakpoint);
static int	is_lonely(char *line, int i);

int	is_a_valid_dollar(char *line, int breakpoint)
{
	int		i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	if (line[breakpoint] != '$')
		return (FALSE);
	if (is_lonely(line, breakpoint) == TRUE)
		return (FALSE);
	while (line[i] != '\0' && i <= breakpoint)
	{
		if (line[i] == VALID_QUOTE)
		{
			if (line[i] == quote_type)
				quote_type = 0;
			else if (line[i] != quote_type && quote_type == 0)
				quote_type = line[i];
		}
		i++;
	}
	if (quote_type != 0 || is_a_delimiter(line, breakpoint) == TRUE)
		return (FALSE);
	return (TRUE);
}

int	is_a_delimiter(char *line, int breakpoint)
{
	if (breakpoint == 0)
		return (FALSE);
	breakpoint--;
	while (line[breakpoint] == ' ' && breakpoint != 0)
		breakpoint--;
	if (breakpoint == 0)
		return (FALSE);
	if (line[breakpoint] == '<' && line[breakpoint - 1] == '<')
		return (TRUE);
	return (FALSE);
}

static int	is_lonely(char *line, int i)
{
	if (line[i + 1] == '\0' || is_a_delimiter(line, i + 1) == TRUE
		|| line[i + 1] == ' ')
		return (TRUE);
	return (FALSE);
}
