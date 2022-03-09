/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_length.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 07:50:42 by nguiard           #+#    #+#             */
/*   Updated: 2021/12/09 07:55:29 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	s_nblen(long long n, int baselen)
{
	int	i;

	i = 0;
	if (n == -9223372036854775807)
		return (19);
	if (n < 0)
		n *= -1;
	while (n > baselen)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int	u_nblen(long long n, int baselen)
{
	int	i;

	i = 0;
	while (n > baselen)
	{
		n /= 10;
		i++;
	}
	return (i);
}
