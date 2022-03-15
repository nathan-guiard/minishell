/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:09:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 10:36:30 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

char *replace_variable_by_content(char *line, int start_var)
{
	int		end_var;
	char	*res;
	char	*part_one;
	char	*part_two;

	end_var = where_is_end_var(line, start_var);
	part_one = ft_substr(line, 0, start_var);
	if (!part_one)
		return (printf("partone\n"), S_ERR);
	part_two = ft_substr(line, end_var, INT_MAX);
	line = only_content(line, start_var);
	res = join(part_one, line);
	if (!res)
		return (printf("1er join\n"),S_ERR);
	free(part_one);
	free(line);
	part_one = res;
	res = join(res, part_two);
	if (!res)
		return (printf("join\n"),S_ERR);
	if (part_two)
		free(part_two);
	free(part_one);
	return (res);
}

char	*only_content(char *line, int start_var)
{
	char *to_free;
	char	*sub;

	sub = ft_substr(line, start_var, where_is_end_var(line, start_var) - start_var);
	to_free = line;
	line = getenv(sub);
	free(to_free);
	free(sub);
	return (line);
}

