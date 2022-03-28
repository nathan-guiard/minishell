/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remaining_strings_are_arguments.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:36:33 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:23:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parstab	remaining_strings_are_arguments(t_parstab tab)
{
	t_lexer	*buff;
	int		i;

	i = 0;
	while (tab[i])
	{
		buff = tab[i];
		while (buff)
		{
			if (buff->symbol == string)
				buff->symbol = argument;
			buff = buff->next;
		}
		i++;
	}
	return (tab);
}
