/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:07:43 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 14:46:14 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

# include "minishell.h"

typedef enum e_types
{
	string = 0,
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
	delimiter = 13,
	red_in_file = 14,
	red_out_file = 15,
	append_file = 16,
	nothing = 17
}	t_symbol;

typedef struct s_lexer
{
	t_symbol		symbol;
	char			*content;
	struct s_lexer	*next;
}	t_lexer;

typedef struct s_exec
{
	char	**envp;
	int		pip[2];
	int		fd_in;
	int		fd_out;
}	t_exec;

# define VALID_PIPE			'\033'
# define VALID_SPACE		-32
# define VALID_REDIN		5
# define VALID_REDOUT		6
# define VALID_APPEND		7
# define VALID_HEREDOC		16
# define VALID_DOLLAR		17
# define NOTHING			18
# define VALID_DQUOTE		19
# define VALID_QUOTE		24
# define REPLACE_THIS_HOLE	4

typedef t_lexer	**t_parstab;

void		ft_lexeradd_front(t_lexer **alst, t_lexer *new);
void		ft_lexeradd_back(t_lexer **alst, t_lexer *new);
void		ft_lexerclear(t_lexer **lst, void (*del)(void *));
void		ft_lexerdelone(t_lexer *lst, void (*del)(void *));
t_lexer		*ft_lexerindex(t_lexer *lst, int index);
t_lexer		*ft_lexerlast(t_lexer *lst);
t_lexer		*ft_lexernew(char *content, t_symbol symbol);
int			ft_lexersize(t_lexer *lst);
void		ft_lexerinsert(t_lexer **alst, t_lexer *to_insert,
				t_lexer *after_this_one);
void		ft_lexerpop(t_lexer **alexer, t_lexer *node);
void		ft_lexerprint(t_lexer *lst);

int			is_a_sep(char c);
int			get_lexer_len(char *line, int i);
char		*get_lexer_content(char *line, int *i);
int			is_a_valid_pipe(char *line, int breakpoint);

t_lexer		*full_symbol_table(char *line);
void		quote_handling(t_lexer **list);
char		*replace_special_char(char *line);
int			is_a_symbol_sep(t_symbol symbol);
t_symbol	get_symbol(char *line);
size_t		sizeof_sep(t_symbol symbol);
void		split_the_unsplitted(t_lexer **list);

t_symbol	get_onechar_symbol(char *line);
t_symbol	get_symbol_replaced(char *line);

int			check_error_full_string(t_lexer *list);
t_parstab	split_the_pipes(t_lexer *list, int pipe_nb);
t_parstab	remaining_strings_are_arguments(t_parstab tab);
int			symbol_change(char *line, int start);
char		*replace_quotes(char *line);

#endif