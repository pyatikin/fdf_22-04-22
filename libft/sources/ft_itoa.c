/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 21:17:03 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/27 12:25:55 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n, int minus)
{
	int	numlen;

	numlen = 1;
	n /= 10;
	while (n)
	{
		numlen++;
		n /= 10;
	}
	return (numlen + minus);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		numlen;
	int		minus;
	int		digit;

	minus = 0;
	if (n < 0)
		minus = 1;
	numlen = ft_numlen(n, minus);
	str = ft_strnew(numlen);
	if (str)
	{
		str[numlen--] = '\0';
		while (numlen >= minus)
		{
			digit = n % 10;
			str[numlen--] = ft_abs(digit) + '0';
			n /= 10;
		}
		if (minus)
			str[0] = '-';
	}
	return (str);
}
