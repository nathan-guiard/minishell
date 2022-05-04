/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:54:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 11:43:58 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_list_int
{
	int					content;
	struct s_list_int	*next;
}	t_list_int;

/* Chars */
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
char		ft_toupper(int c);
char		ft_tolower(int c);

/* Strings */
size_t		ft_strlen(const char *s);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strnstr(const char *big, const char *little, size_t len);
int			ft_atoi(const char *nptr);

/* Memoire */
void		*ft_memset(void *s, int c, size_t n);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);

/* Malloc */
void		*ft_calloc(size_t nmemb, size_t size);
char		*ft_strdup(const char *s);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);

/* Pointeur sur fonction */
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));

/* fd */
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

/* Listes */
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **alst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **alst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **clear, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstindex(t_list *lst, int index);
void		ft_lstpop(t_list **alst, t_list *node);

t_list_int	*ft_lstnew_int(int content);
void		ft_lstadd_front_int(t_list_int **alst, t_list_int *new);
int			ft_lstsize_int(t_list_int *lst);
t_list_int	*ft_lstlast_int(t_list_int *lst);
void		ft_lstadd_back_int(t_list_int **alst, t_list_int *new);
void		ft_lstdelone_int(t_list_int *lst);
void		ft_lstclear_int(t_list_int **clear);
void		ft_lstiter_int(t_list_int *lst, void (*f)(int));
t_list_int	*ft_lstmap_int(t_list_int *lst, int (*f)(int));
void		ft_lstprint_int(t_list_int *lst);
t_list_int	*ft_lstindex_int(t_list_int *lst, int index);

/* Pratique */
char		*get_whole_file(int fd);
int			ft_xtoi_comma(char *s);
void		free_all(char **s);
char		*ft_strrm_index(char *tab, int index);

/* get_next_line */

# ifndef GET_NEXT_LINE_H
#  define GET_NEXT_LINE_H

#  define FD_MAX 1024
#  ifndef BUFFER_SIZE
#   define BUFFER_SIZE 500000
#  endif

/* get_next_line */
char		*get_next_line(int fd);
char		*get_line(char *s, int i);
char		*new_rest(char *rest);
char		*read_until_newline(int fd, char *rest);
char		*the_line(char *s);

/* Utils */
char		*ft_strchr_g(const char *s, int c);
char		*join(char *rest, char *buff);

# endif

/* ft_printf */
# ifndef FT_PRINTF_H
#  define FT_PRINTF_H

/* Enum t_type */
typedef enum e_type
{
	rien = 0,
	nombre = 1,
	caractere = 2,
	non_signe = 3,
	pointeur = 4,
	hex_min = 5,
	hex_maj = 6,
	pourcent = 7,
	chaine = 8,
	binaire = 9,
}	t_type;

/* Variables */
#  define HEX_MIN "0123456789abcdef"
#  define HEX_MAJ "0123456789ABCDEF"
#  define DEC "0123456789"
#  define TYPES "cspdiuxX%"

/* Parsing */
t_type		*printf_parsing(const char *s);
t_type		is_valid(char c);

/* Print arguments */
int			count_putstr(char *s);
int			count_putchar(char c);
int			count_putunsigned(unsigned int n);
int			count_puthex_min(unsigned int n);
int			count_puthex_maj(unsigned int n);
int			count_putprct(void);
int			count_putnbr(int n);
int			count_putptr(void *n);
int			count_putbin(unsigned int n);

/* PRINTF */
int			ft_printf(const char *s, ...);
# endif

/* ft_colors */
# ifndef FT_COLORS_H
#  define FT_COLORS_H

#  define C_BOLD 1
#  define C_FADED 2
#  define C_ITALIC 3
#  define C_UNDERLINE 4
#  define C_BLINK 5
#  define C_BLINKOFF 25
#  define C_REVERSE 7
#  define C_HIDE 8
#  define C_CROSSED 9

#  define C_BLACK 0
#  define C_RED 1
#  define C_GREEN 2
#  define C_YELLOW 3
#  define C_BLUE 4
#  define C_MAGENTA 5
#  define C_CYAN 6
#  define C_WHITE 7
#  define C_GREY 8
#  define C_HBLACK 8
#  define C_HRED 9
#  define C_HGREN 10
#  define C_HYELLOW 11
#  define C_HBLUE 12
#  define C_HMAGENTA 13
#  define C_HCYAN 14
#  define C_HWHITE 15

#  define C_RESET 42000

#  define C_BASE "\033["
#  define C_BG "48;5;"
#  define C_FG "38;5;"
#  define C_BGRESET "49;"
#  define C_FGRESET "39m"

/* Fonctions de base */
void		set_layout(unsigned int fg, unsigned int bg, unsigned int style);
void		delete_std(int n);

/* Need printf */
void		set_layout_printf(unsigned int fg,
				unsigned int bg, unsigned int style);
void		delete_std_printf(int n);
void		loading_bar(int progression);

# endif

#endif
