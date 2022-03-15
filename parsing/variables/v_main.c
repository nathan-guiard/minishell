/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:16:54 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 10:32:56 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"


char *test(char *line)
{
	return (replace_variables(line));
}

/*	Remplace les variables par leur valeur dans l'environnement
	Retour la ligne cahngee ou alors retourne S_ERR en cas d'erreur	*/
char *replace_variables(char *line)
{
	int	i;
	int ret;

	ret = 0;
	i = 0;
	while (line[i])
	{
		ret = is_a_valid_env(line, i);
		if (line[i] == '$' && ret == M_ERR)
			return (printf("Main: return S_MERR\n"), S_MERR);
		else if (line[i] == '$' && ret == TRUE)
		{
			line = replace_variable_by_content(line, i);
			if (ft_strcmp(S_ERR, line) == 0)
				return (printf("Main: retour S_ERR\n"), S_ERR);
		}
		//else if (line[i] == '$' && ret == FALSE)
		//{
		//	line = replace_variable_by_nothing(line, i);
		//	if (ft_strcmp(S_ERR, line) == 0)
		//		return (S_ERR);
		//}
				i++;
	}
	return (line);
}

int	is_a_valid_env(char *line, int i)
{
	char *test;
	char *ptr;
	int	save;
	int	j;

	i++;
	save = i;
	while (line[i] != '\0' && line[i] != '\f' && line[i] != '\t'
		&& line[i] != '\n' && line[i] != '\r' && line[i] != '\v'
		&& line[i] != ' ')
		i++;
	if (i - save == 0)
		return (ALONE);
	test = malloc(sizeof(char) * ((i - save) + 1));
	if (!test)
		return (M_ERR);
	j = 0;
	while (save + j < i)
	{
		printf("line[%d] ok\n", save + j);
		test[j] = line[save + j];
		j++;
	}
	printf("fnin\n");
	test[j] = '\0';
	ptr = getenv(test);
	free(test);
	if (ptr)
		return (printf("RETURN TRUE\n"), TRUE);
	return (printf("RETURN FALSE\n"), FALSE);	
}

int	where_is_end_var(char *line, int start_var)
{
	int		i;
	char	search;

	i = start_var;
	if (line[i + 1] == '$')
		search = '$';
	else
		search = ' ';
	while (line[i] == search && line[i])
	{
		if (line[i] == '\f' || line[i] == '\t' || line[i] == '\n'
			|| line[i] == '\r' || line[i] == '\v')
			break;
		i++;
	}
	if (search == '$' && line[i] != search)
		return (P_ERR);
	return (i);
}