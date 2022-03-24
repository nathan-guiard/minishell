/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:31:47 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 09:28:27 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	how_many_pipes(t_lexer *list);

t_parstab full_parsing(char *line)
{
//	t_parstab	tab;
	t_lexer		*first_part;
//	int			pipe_nb;

	first_part = full_symbol_table(line);
	if (!first_part)
		return (NULL);
	ft_lexerprint(first_part);
	//pipe_nb = how_many_pipes(first_part);
	//tab = split_the_pipes(first_part, pipe_nb);
	//return (tab);
	return (NULL);
}

int	how_many_pipes(t_lexer *list)
{
	int		res;
	t_lexer	*buff;

	buff = list;
	res = 0;
	while (buff)
	{
		if (buff->symbol == sb_pipe)
			res++;
		buff = buff->next;
	}
	return (res);
}