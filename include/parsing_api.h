/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_api.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:18:06 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 14:14:00 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_API_H
# define PARSING_API_H

# include "minishell.h"

# define HEREDOC_STRING	"\009\n\5a heredoc has been detected"

char	*api_last_red_out(t_lexer *list);
char	*api_last_red_in(t_lexer *list);
char	**api_get_command_tab(t_lexer *list);
char	**api_every_red_in(t_lexer *list);

#endif