/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 15:54:53 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:24:50 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*replace_quotes(char *line)
{
	int	quote_type;
	int	i;

	i = 0;
	quote_type = 0;
	while (line[i])
	{
		if (line[i] == '\"' || line[i] == '\'')
		{
			if (quote_type == 0)
			{
				quote_type = line[i];
				line[i] -= 15;
			}
			else if (quote_type == line[i])
			{
				line[i] -= 15;
				quote_type = 0;
			}
		}
		i++;
	}
	return (line);
}
