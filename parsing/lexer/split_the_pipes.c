/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_the_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:09:17 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:25:47 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Cree un tableau de listes avec le content de chaques pipes
	dans les listes, pas plus									*/
t_parstab	split_the_pipes(t_lexer *list, int pipe_nb)
{
	t_parstab	res;
	t_lexer		*new;
	t_lexer		*buff;
	int			i;
	char		*new_content;

	res = ft_calloc(sizeof(t_lexer *), (pipe_nb + 2));
	if (!res)
		return (NULL);
	buff = list;
	i = 0;
	while (buff)
	{
		if (buff->symbol != sb_pipe)
		{
			new_content = ft_strdup(buff->content);
			new = ft_lexernew(new_content, buff->symbol);
			ft_lexeradd_back(&(res[i]), new);
		}
		else
			i++;
		buff = buff->next;
	}
	ft_lexerclear(&list, free);
	return (res);
}
