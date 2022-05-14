/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_equal_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:11:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 15:32:04 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*without_plus(char *str);

char	*plus_equal_export(char *str)
{
	t_list	*node;
	char	*res;
	char	*no_plus;

	no_plus = without_plus(str);
	node = get_env_node(no_plus);
	if (!node)
		return (no_plus);
	res = ft_strjoin(node->content, no_plus);
	if (!res)
		ft_putstr_fd(MERR_STR, 2);
	return (res);
}

static char	*without_plus(char *str)
{
	char	*res;
	int		i;
	int		j;

	res = malloc(sizeof(char) * (ft_strlen(str)));
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), NULL);
	j = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '+')
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
