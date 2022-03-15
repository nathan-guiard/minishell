/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:14:19 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 09:56:06 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VARIABLES_H
# define VARIABLES_H

int			is_a_valid_env(char *line, int i);
char		*replace_variable_by_content(char *line, int i);
int			where_is_end_var(char *line, int start_var);
char		*only_content(char *line, int start_var);

#endif