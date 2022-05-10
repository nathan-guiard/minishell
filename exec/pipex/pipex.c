/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 13:49:37 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/10 22:10:00 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mon_pipex_eclate(t_parstab parsing);

t_exec	init_struct_exec(t_lexer *ls, char **env)
{
	t_exec		ex;
	t_symbol	symbout;

	ex.envp = env;
	ex.cmd = api_full_command(ls);
	if (api_last_red_in(ls) != NULL)
			ex.fd_in = open(api_last_red_in(ls), O_RDONLY);
	else
			ex.fd_in = STDIN_FILENO;
	if (api_last_red_out(ls) == NULL)
		ex.fd_out = STDOUT_FILENO;
	else if (api_last_red_out(ls) != NULL)
	{
		symbout = api_get_symb(ls);
		if (symbout == red_out)
			ex.fd_out = open(api_last_red_out(ls), O_WRONLY | O_CREAT
					| O_TRUNC);
		else if (symbout == append)
			ex.fd_out = open(api_last_red_out(ls), O_WRONLY | O_CREAT
				| O_APPEND);
	}
	return (ex);
}

char	*prep_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*part_path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i] && cmd != NULL)
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_tabtab(paths);
			return (path);
		}
		free(path);
		i++;
	}
	free_tabtab(paths);
	return (NULL);
}

void	pipex(t_parstab	parsing, char **envp)
{
	int		i;
	t_lexer	*buff;
	t_exec	ex;
	int		pip[2];

	i = 0;
	while (parsing[i])
	{
		buff = parsing[i];
		open_all_red_out(buff);
		i++;
	}
	i = 0;
	if (1)
	{
		while (parsing[i])
		{
			if (pipe(pip) == -1)
				return ;
			ex = init_struct_exec(parsing[i], envp);
			exec_cmd(parsing, &ex, i, pip);
			i++;
		}
		close(0);
	}
}

//	pour faire mes tests
/*void	mon_pipex_eclate(t_parstab tab)
{
	int	i;

	i = 0;
	while (tab[i] != NULL)
	{
		set_layout_printf(C_GREEN, C_RESET, C_RESET);
		printf("Pipe nb %d, taille de la liste: %d \n",
			i, ft_lexersize(tab[i]));
		set_layout(C_BLUE, C_RESET, C_ITALIC);
		set_layout(C_BLUE, C_RESET, C_BOLD);
		ft_lexerprint(tab[i]);
		set_layout_printf(C_RESET, C_RESET, C_RESET);
		i++;
	}
	free_parstab(tab);
}*/
