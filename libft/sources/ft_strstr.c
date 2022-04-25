/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/30 20:11:41 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/26 00:12:25 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*h;
	size_t	needle_len;
	size_t	i;
	size_t	j;

	h = (char *)haystack;
	needle_len = ft_strlen(needle);
	if (!needle_len)
		return (h);
	i = 0;
	while (h[i])
	{
		j = 0;
		while (needle[j] && needle[j] == h[i + j])
			j++;
		if (j == needle_len)
			return (&h[i]);
		i++;
	}
	return (NULL);
}
