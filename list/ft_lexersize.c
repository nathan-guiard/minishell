/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexersize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 17:58:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:35:58 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_lexersize(t_lexer *lst)
{
	t_lexer	*buff;
	int		i;

	if (!lst)
		return (0);
	i = 1;
	buff = lst;
	while (buff->next != NULL)
	{
		i++;
		buff = buff->next;
	}
	return (i);
}
