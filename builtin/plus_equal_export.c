/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_equal_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:11:15 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 18:33:23 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*without_plus(char *str);
void		unset_plus_equal(char *str);

char	*plus_equal_export(char *str)
{
	t_list	*node;
	char	*res;
	char	*no_plus;
	char	*after_equal;
	char	*before_equal;

	no_plus = without_plus(str);
	before_equal = ft_substr(no_plus, 0, where_is_equal_sign(no_plus));
	node = get_env_node(before_equal);
	free(before_equal);
	if (!node)
		return (unset_plus_equal(no_plus), no_plus);
	after_equal = ft_substr(no_plus, where_is_equal_sign(no_plus) + 1, INT_MAX);
	res = ft_strjoin(node->content, after_equal);
	if (!res)
		ft_putstr_fd(MERR_STR, 2);
	unset_plus_equal(no_plus);
	free(no_plus);
	free(after_equal);
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

void	unset_plus_equal(char *str)
{
	char	**tab;
	char	*truc;

	tab = ft_calloc(sizeof(char *), 3);
	if (!tab)
		return ;
	truc = ft_substr(str, 0, where_is_equal_sign(str));
	if (!truc)
		return (free(tab));
	tab[0] = "unset";
	tab[1] = truc;
	unset(tab);
	free(tab);
	free(truc);
}
