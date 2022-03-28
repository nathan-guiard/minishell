/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexeradd_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:10:55 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:19:20 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexeradd_back(t_lexer **alst, t_lexer *new)
{
	t_lexer	*buff;

	if (!*alst)
	{
		*alst = new;
		return ;
	}
	buff = ft_lexerlast(*alst);
	buff->next = new;
}
