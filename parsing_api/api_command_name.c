/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_command_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 15:37:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:25:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Envoie le nom de la commande
	A NE PAS FREE					*/
char	*api_command_name(t_lexer *list)
{
	t_lexer	*buff;

	if (!list)
		return (NULL);
	buff = list;
	while (buff)
	{
		if (buff->symbol == command)
			return (buff->content);
		buff = buff->next;
	}
	return (NULL);
}
