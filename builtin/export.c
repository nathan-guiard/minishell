/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:08:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 18:31:55 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		real_export(char **args);
int			is_a_valid_export(char *str);
static char	**only_variable_name(char **args);

void	export(char **args)
{
	char	**only_variable;
	t_list	*buff;

	buff = g_env;
	if (!args || !args[1])
	{
		while (buff)
		{
			printf("declare -x %s\n", (char *)buff->content);
			buff = buff->next;
		}
		return ;
	}
	only_variable = only_variable_name(args);
	unset(only_variable);
	free_tabtab(only_variable);
	real_export(args);
}

static char	**only_variable_name(char **args)
{
	char	**res;
	int		i;
	int		equal;

	i = 0;
	while (args[i])
		i++;
	res = ft_calloc(sizeof(char *), i + 1);
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), NULL);
	i = 0;
	while (args[i])
	{
		equal = where_is_equal_sign(args[i]);
		if (equal == NONE || equal == 0)
			res[i] = ft_strdup(args[i]);
		else
			res[i] = ft_substr(args[i], 0, equal);
		i++;
	}
	res[i] = NULL;
	return (res);
}

void	real_export(char **args)
{
	int		i;
	t_list	*node;
	int		ret;

	i = 1;
	while (args[i])
	{
		ret = is_a_valid_export(args[i]);
		if (ft_strnstr(args[i], "+=", INT_MAX) != NULL
			&& ret == TRUE)
		{
			node = ft_lstnew(plus_equal_export(args[i]));
			ft_lstadd_back(&g_env, node);
		}
		else if (ret == TRUE)
		{
			node = ft_lstnew(ft_strdup(args[i]));
			ft_lstadd_back(&g_env, node);
		}
		else if (ret == FALSE)
			print_exp_err(args[i]);
		i++;
	}
}

int	is_a_valid_export(char *str)
{
	char	*sub;
	int		equal;

	equal = where_is_equal_sign(str);
	if (equal == NONE)
		return (NONE);
	if (equal == 0 || (equal == 1 && str[0] == '+'))
		return (FALSE);
	sub = ft_substr(str, 0, equal);
	if (!sub)
		return (FALSE);
	if (ft_strchr(sub, '\'') == NULL && ft_strchr(sub, '\"') == NULL
		&& ft_strchr(sub, '$') == NULL && ft_strchr(sub, '=') == NULL)
		return (free(sub), TRUE);
	return (free(sub), FALSE);
}

int	where_is_equal_sign(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (i);
		i++;
	}
	return (NONE);
}
