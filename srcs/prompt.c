/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:00:22 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 15:15:57 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_only_dir_name(char *abs_dir);
static char	*get_full_prompt(char *only_dir);
static char	*is_home(char *abs_dir);

/*	Revonvoie la chaine malloced du prompt, a free.	
	Si il y a une erreur lors de la recuperation du
	path, affiche un path "somewhere" et une erreur	*/
char	*prompt(void)
{
	char	*res;
	char	*prompt_text;

	prompt_text = get_prompt_text();
	if (prompt_text == NULL)
		prompt_text = get_full_prompt(ft_strdup("somewhere"));
	res = readline(prompt_text);
	free(prompt_text);
	return (res);
}

/*	Malloc une string qui a tout le path de curr dir 
	Si il y a un probleme, donne "somewhere" comme string
	et affiche une erreur, on peut enlever l'erreur si jamais	*/
char	*get_prompt_text(void)
{
	char	*abs_dir;
	char	*only_dir;

	abs_dir = malloc(10000);
	if (!abs_dir)
		return (S_MERR);
	if (getcwd(abs_dir, 9999) == NULL)
		return (ft_putstr_fd("getcwd error\n", 2), NULL);
	only_dir = get_only_dir_name(abs_dir);
	return (get_full_prompt(only_dir));
}

/*	Transforme le chemin absolu en "que le dossier" */
static char	*get_only_dir_name(char *abs_dir)
{
	char	*res;
	int		i;

	i = ft_strlen(abs_dir);
	res = is_home(abs_dir);
	if (res)
		return (res);
	if (abs_dir[1] == '\0')
		return (free(abs_dir), ft_strdup("/"));
	while (abs_dir[i] != '/' && i != 0)
		i--;
	res = ft_substr(abs_dir, i + 1, INT_MAX);
	free(abs_dir);
	return (res);
}

/*	Rend le prompt final avec ce qu'il y a autour, free only_dir*/
static char	*get_full_prompt(char *only_dir)
{
	char	*res;
	char	*to_free;

	res = ft_strjoin("\033[0m\033[1;37m[\033[0mminishell: \033[32m", only_dir);
	if (!res)
		return (free(only_dir), NULL);
	free(only_dir);
	to_free = res;
	res = ft_strjoin(res, "\033[1;37m]\033[0m ");
	if (to_free)
		free(to_free);
	return (res);
}

/*	Si on est dans notre home, renvoie "~" sinon renvoie NULL		*/
static char	*is_home(char *abs_dir)
{
	char	*home;

	home = ft_getenv("HOME");
	if (ft_strcmp(abs_dir, home) == 0)
		return (free(abs_dir), ft_strdup("~"));
	return (NULL);
}
