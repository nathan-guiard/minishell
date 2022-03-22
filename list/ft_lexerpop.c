/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexerpop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:37:08 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/22 14:47:05 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexerpop(t_lexer **alexer, t_lexer *node)
{
	t_lexer	*following;
	t_lexer	*buff;
	t_lexer *before;

	if (!alexer || !(node->content) || !node)
		return ;
	//if (node->next == NULL)
	//	return (ft_lexerdelone(node, free));
	buff = *alexer;
	before = NULL;
	while (buff)
	{
		if (buff == node)
		{
			following = node->next;
			if (before)
			{
				before->next = following;
			//	ft_lexerdelone(node, free);
			}
			else
			{
				*alexer = following;
			//	ft_lexerdelone(node, free);
			}
			break ;
		}
		before = buff;
		buff = buff->next;
	}
}
