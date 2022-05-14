/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:16:54 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 17:59:41 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

char	*change_the_variable(char *line, int *i);

/*	Remplace les variables par leur valeur dans l'environnement
	Retour la ligne changee ou alors retourne NULL en cas d'erreur	*/
char	*replace_variables(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == VALID_DOLLAR)
		{
			line = change_the_variable(line, &i);
			if (!line)
				return (NULL);
		}
		if ((size_t)i < ft_strlen(line))
			i++;
	}
	return (line);
}

/*	Prend la premiere partie avant et apres la variable qu'on veut changer
	puis prend la valeur de la varaible dans l'env et join le tout			*/
char	*replace_variable_by_content(char *line, int start_var)
{
	int		end_var;
	char	*res;
	char	*part_one;
	char	*part_two;

	end_var = where_is_end_var(line, start_var);
	part_one = ft_substr(line, 0, start_var);
	if (!part_one)
		return (ft_putstr_fd(MERR_STR, 2), free(line), NULL);
	part_two = ft_substr(line, end_var, INT_MAX);
	if (!part_two)
		return (ft_putstr_fd(MERR_STR, 2), free(line), free(part_one)
			, NULL);
	line = only_content(line, start_var);
	res = join(part_one, line);
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), NULL);
	res = join(res, part_two);
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), NULL);
	free(part_two);
	free(line);
	return (res);
}

/*	Ne recupere que le contenu de la variable qui se trouve a l'indice
	start_var de la chaine line												*/
char	*only_content(char *line, int start_var)
{
	char	*to_free;
	char	*sub;

	if (!line)
		return (NULL);
	sub = ft_substr(line, start_var + 1,
			where_is_end_var(line, start_var) - start_var - 1);
	if (!sub)
		return (ft_putstr_fd(MERR_STR, 2), NULL);
	to_free = line;
	line = ft_getenv(sub);
	free(to_free);
	free(sub);
	return (line);
}

/*	Join ce qu'il y a avant et apres la variable inexistante
	avec NOTHING entre les deux									*/
char	*replace_variable_by_nothing(char *line, int start_var)
{
	int		end_var;
	char	*res;
	char	*part_one;
	char	*part_two;

	end_var = where_is_end_var(line, start_var);
	part_one = ft_substr(line, 0, start_var);
	if (!part_one)
		return (ft_putstr_fd(MERR_STR, 2), free(line), NULL);
	part_one = join(part_one, "\022");
	if (!part_one)
		return (ft_putstr_fd(MERR_STR, 2), free(line), NULL);
	part_two = ft_substr(line, end_var, INT_MAX);
	if (!part_two)
		return (ft_putstr_fd(MERR_STR, 2), free(line), free(part_one)
			, NULL);
	res = join(part_one, part_two);
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), free(line), free(part_two)
			, NULL);
	free(part_two);
	free(line);
	return (res);
}

char	*change_the_variable(char *line, int *i)
{
	int	ret;

	ret = is_a_valid_env(line, *i);
	if (ret == TRUE)
	{
		line = replace_variable_by_content(line, *i);
		if (!line)
			return (NULL);
		*i = 0;
	}
	else if (ret == FALSE)
	{
		line = replace_variable_by_nothing(line, *i);
		if (!line)
			return (NULL);
		*i = 0;
	}
	return (line);
}
