/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:03:25 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:25:05 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_a_delimiter(char *line, int breakpoint);

int	is_a_valid_dollar(char *line, int breakpoint)
{
	int		i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	if (breakpoint == 0 && line[0] == '$')
		return (TRUE);
	if (line[breakpoint] != '$')
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
	breakpoint--;
	while (line[breakpoint] == ' ' && breakpoint != 0)
		breakpoint--;
	if (breakpoint == 0)
		return (FALSE);
	if (line[breakpoint] == '<' && line[breakpoint - 1] == '<')
		return (TRUE);
	return (FALSE);
}
