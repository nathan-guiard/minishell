/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:08 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:20:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexerpop(t_lexer **alexer, t_lexer *node)
{
	t_lexer	*following;
	t_lexer	*buff;
	t_lexer	*before;

	if (!alexer || !(node->content) || !node)
		return ;
	buff = *alexer;
	before = NULL;
	while (buff)
	{
		if (buff == node)
		{
			following = node->next;
			if (before)
				before->next = following;
			else
				*alexer = following;
			break ;
		}
		before = buff;
		buff = buff->next;
	}
}
