/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 18:30:49 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/14 18:27:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_line_in_submode(char *line, char *delimiter, char *str)
{
	int	i;

	i = 1;
	while (line)
	{
		free(line);
		line = readline("> ");
		if (heredoc_err(delimiter, line, i) == TRUE)
			break ;
		if (!str)
			str = ft_strdup(line);
		else
		{
			str = join(str, "\n");
			str = join(str, line);
		}
		i++;
	}
	if (str == NULL)
		return (ft_strdup("\n"));
	str = join(str, "\n");
	free(line);
	return (str);
}

static char	*stock_buffer(t_lexer *ls)
{
	char	*line;
	char	*str;
	char	*delimiter;

	line = (char *)malloc(sizeof(char));
	delimiter = api_heredoc_delimiter(ls);
	str = get_line_in_submode(line, delimiter, NULL);
	return (str);
}

static char	*heredoc_child_proc(int *pipe_fds, t_lexer *ls)
{
	char	*buffer;

	heredoc_sig();
	close(pipe_fds[READ]);
	buffer = stock_buffer(ls);
	write(pipe_fds[WRITE], buffer, ft_strlen(buffer) + 1);
	close(pipe_fds[WRITE]);
	free(buffer);
	exit(0);
}

static void	heredoc_parent_proc(int *pipe_fds)
{
	wait(NULL);
	close(pipe_fds[WRITE]);
	dup2(pipe_fds[READ], STDIN_FILENO);
}

int	heredoc_par(t_parstab tab, int i)
{
	pid_t	pid;
	int		pipe_fds[2];

	if (pipe(pipe_fds) == -1)
		return (1);
	end_signals();
	pid = fork();
	if (pid == -1)
		return (1);
	else if (pid == 0)
		heredoc_child_proc(pipe_fds, tab[i]);
	else
		heredoc_parent_proc(pipe_fds);
	return (0);
}
