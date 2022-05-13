/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ret_value.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:26:44 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 17:48:12 by nguiard          ###   ########.fr       */
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
	if (!args)
		return (ft_putstr_fd(MERR_STR, 2));
	number = ft_itoa(i);
	if (!number)
		return (free(args), ft_putstr_fd(MERR_STR, 2));
	args[0] = ft_strdup("export");
	args[1] = ft_strjoin("?=", number);
	args[2] = NULL;
	export(args);
	free(number);
	free_tabtab(args);
}
