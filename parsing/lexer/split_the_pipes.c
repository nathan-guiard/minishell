/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_the_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:09:17 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 09:32:43 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_parstab	split_the_pipes(t_lexer *list, int pipe_nb)
{
	t_parstab	res;
	t_lexer		*new;
	t_lexer		*buff;
	int			i;
	char		*new_content;

	res = ft_calloc(sizeof(t_lexer *), (pipe_nb + 1));
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
	res[pipe_nb + 1] = NULL;
	return (res);
}