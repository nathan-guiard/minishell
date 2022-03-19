/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexernew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:23:35 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 11:41:04 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer	*ft_lexernew(char *content, t_symbol symbol)
{
	t_lexer	*a;

	a = malloc(sizeof(t_lexer));
	if (!a)
		return (NULL);
	a->content = content;
	a->symbol = symbol;
	a->next = NULL;
	return (a);
}
