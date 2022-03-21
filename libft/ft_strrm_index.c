/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrm_index.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:30:26 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 16:38:09 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Enleve l'index <index> du tableau	*/
char	*ft_strrm_index(char *str, int index)
{
	char	*before;
	char	*after;
	char	*res;

	before = ft_substr(str, 0, index);
	if (!before)
		return (NULL);
	after = ft_substr(str, index + 1, INT_MAX);
	if (!after)
		return (free(before), NULL);
	res = ft_strjoin(before, after);
	if (!res)
		return (free(before), free(after), NULL);
	free(before);
	free(after);
	return (res);
}
