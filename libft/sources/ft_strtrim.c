/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 16:47:49 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/26 00:17:54 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*result;
	size_t	i;
	size_t	start;
	size_t	finish;

	if (!s)
		return (NULL);
	i = 0;
	start = 0;
	finish = ft_strlen(s);
	while (ft_isblank(s[start]) || s[start] == '\n')
		start++;
	while (finish && (ft_isblank(s[finish - 1]) || s[finish - 1] == '\n'))
		finish--;
	if ((result = ft_strnew((finish > start) ? (finish - start) : 0)))
	{
		while (start < finish)
			result[i++] = s[start++];
		result[i] = '\0';
	}
	return (result);
}
