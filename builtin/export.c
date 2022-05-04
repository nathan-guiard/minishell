/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:08:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 11:17:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_nothing(void);
void	real_export(char **args);
int		where_is_equal_sign(char *str);
int		is_a_valid_export(char *str);

void	export(char **args)
{
	if (!args || !args[1])
	{
		ft_export_nothing();
		return ;
	}
	unset(args);
	real_export(args);
}

void	ft_export_nothing(void)
{
	t_list	*buff;

	buff = g_env;
	while (buff)
	{
		printf("declare -x %s\n", (char *)buff->content);
		buff = buff->next;
	}
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
		if (ret == TRUE)
		{
			node = ft_lstnew(ft_strdup(args[i]));
			ft_lstadd_back(&g_env, node);
		}
		else if (ret == NONE)
		{
			node = ft_lstnew(ft_strjoin(args[i], "="));
			ft_lstadd_back(&g_env, node);
		}
		else if (ret == FALSE)
			printf("export: `%s': not a valid identifier\n", args[i]);
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
	if (equal == 0)
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
