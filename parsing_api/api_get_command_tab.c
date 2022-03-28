/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_get_command_tab.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/28 10:59:57 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:10:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Prend en arguments un liste et renvoie le tableau de tableau
	avec la commande et les arguments pour execve.
	A FREE															*/
char	**api_get_command_tab(t_lexer *list)
{
	char	**res;
	int		len;
	int		i;
	t_lexer	*arg_list;
	t_lexer	*to_free;

	arg_list = get_all_args(list);
	to_free = arg_list;
	len = ft_lexersize(arg_list);
	res = ft_calloc(len + 1, sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (arg_list)
	{
		res[i] = ft_strdup(arg_list->content);
		i++;
		arg_list = arg_list->next;
	}
	res[i];
	ft_lexerclear(to_free, free);
	return (res);
}