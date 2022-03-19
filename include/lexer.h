/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:07:43 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/17 15:29:25 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum	e_types
{
	red_in = 1,
	red_out = 2,
	append = 3,
	heredoc = 4,
	path = 5,
	command = 6,
	sb_builtin = 7,
	argument = 8,
	variable = 9,
	quote = 10,
	d_quote = 11,
	sb_pipe = 12,
	string = 13,
}	t_symbol;

typedef struct s_lexer
{
	t_symbol		symbol;
	char			*content;
	struct	s_lexer	*next;
}	t_lexer;

void	ft_lexeradd_front(t_lexer **alst, t_lexer *new);
void	ft_lexeradd_back(t_lexer **alst, t_lexer *new);
void	ft_lexerclear(t_lexer **lst, void (*del)(void *));
void	ft_lexerdelone(t_lexer *lst, void (*del)(void *));
t_lexer	*ft_lexerindex(t_lexer *lst, int index);
t_lexer	*ft_lexerlast(t_lexer *lst);
t_lexer	*ft_lexernew(char *content, t_symbol symbol);
int		ft_lexersize(t_lexer *lst);


int		is_a_sep(char c);
int		get_lexer_len(char *line, int i);
char	*get_lexer_content(char *line, int *i);
int		is_a_valid_pipe(char *line, int breakpoint);

#endif