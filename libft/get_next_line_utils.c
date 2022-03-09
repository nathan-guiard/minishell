/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 11:29:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/01/29 11:02:27 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_g(const char *s, int c)
{
	int		i;
	char	*p;

	if (!s)
		return (0);
	p = (char *)s;
	i = 0;
	while (s[i])
	{
		if (s[i] == (c % 256))
			return (p);
		i++;
		p++;
	}
	if (s[i] == '\0' && c == '\0')
		return (p);
	return (NULL);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	size_t	a;
	char	*res;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	a = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *)malloc(a * sizeof(char));
	if (!res)
		return (NULL);
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		res[i + j] = s2[j];
		j++;
	}
	res[i + j] = '\0';
	return (res);
}

char	*join(char *rest, char *buff)
{
	char	*new_rest;

	if (!rest)
	{
		rest = malloc(sizeof(char));
		if (!rest)
			return (NULL);
		rest[0] = '\0';
	}
	new_rest = ft_strjoin_g(rest, buff);
	free(rest);
	rest = NULL;
	return (new_rest);
}
