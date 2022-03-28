/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_last_red_out.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:08:20 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:30:25 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Renvoie nom du dernier fichier de redirection out ou
	NULL si il y en a pas.
	En gros c'est le fichier qu'on doit remplir
	A NE PAS FREE										*/
char	*api_last_red_out(t_lexer *list)
{
	t_lexer	*buff;
	char	*last;

	last = NULL;
	buff = list;
	while (buff)
	{
		if ((buff->symbol == append || buff->symbol == red_out)
			&& buff->next)
			last = buff->next->content;
		buff = buff->next;
	}
	return (last);
}
