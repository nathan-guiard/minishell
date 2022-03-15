/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_replace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:09:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 13:20:36 by nguiard          ###   ########.fr       */
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
		return (S_ERR);
	part_two = ft_substr(line, end_var, INT_MAX);
	//printf("\\\\\\\\%s %d %s\n",line, end_var, part_two);
	line = only_content(line, start_var);
	//printf("Only content: %s\n", line);
	res = join(part_one, line);
	//printf("apres premier join: %s\n", res);
	if (!res)
		return (S_ERR);
	res = join(res, part_two);
	//printf("apres deuxieme join: %s\n", res);
	if (!res)
		return (S_ERR);
	if (part_two)
		free(part_two);
	return (res);
}

char	*only_content(char *line, int start_var)
{
	char *to_free;
	char	*sub;

	if (line[start_var] == '{')
		start_var++;
	sub = ft_substr(line, start_var + 1, where_is_end_var(line, start_var) - start_var - 1);
	//printf("Sub (getenv): %s (%ld)\n", sub, ft_strlen(sub));
	to_free = line;
	line = getenv(sub);
	if (to_free)
		free(to_free);
	if (sub)
		free(sub);
	return (line);
}

char *replace_variable_by_nothing(char *line, int start_var)
{
	int		end_var;
	char	*res;
	char	*part_one;
	char	*part_two;

	end_var = where_is_end_var(line, start_var);
	part_one = ft_substr(line, 0, start_var);
	if (!part_one)
		return (S_ERR);
	part_two = ft_substr(line, end_var, INT_MAX);
	res = join(part_one, part_two);
	free(part_two);
	return (res);
}