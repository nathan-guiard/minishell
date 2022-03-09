/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 11:34:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/04 03:12:50 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_putstr(char *s)
{
	int	i;

	if (!s)
		return (count_putstr("(null)"));
	i = 0;
	while (s[i])
	{
		count_putchar(s[i]);
		i++;
	}
	return (i);
}
