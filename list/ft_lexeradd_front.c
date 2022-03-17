/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexeradd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:40:26 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 11:44:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_lexeradd_front(t_lexer **alst, t_lexer *new)
{
	if (!*alst)
	{
		*alst = new;
		return ;
	}
	new->next = *alst;
	*alst = new;
}
