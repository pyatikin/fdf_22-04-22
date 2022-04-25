/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/04 15:47:51 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/26 00:53:34 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strnlen(const char *s, size_t maxlen)
{
	char	*ptr;

	ptr = ft_memchr(s, '\0', maxlen);
	if (ptr)
		return ((size_t)(ptr - s));
	return (maxlen);
}
