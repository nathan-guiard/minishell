/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ret_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:26:44 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:19:12 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	export $? avec la valeur de i
	i est en unsigned char car les returns sont max 256 takapteeee	*/
void	set_ret_value(unsigned char i)
{
	char	*number;
	char	**args;

	args = ft_calloc(3, sizeof(char *));
	number = ft_itoa(i);
	args[0] = ft_strdup("export");
	args[1] = ft_strjoin("?=", number);
	args[2] = NULL;
	export(args);
	free(number);
	free_tabtab(args);
}
