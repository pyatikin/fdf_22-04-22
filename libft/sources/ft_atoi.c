/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/01 15:35:30 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/26 21:09:54 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dopat(int *sign, const char *str, size_t *i);

int	ft_atoi(const char *str)
{
	unsigned long	result;
	unsigned long	border;
	size_t			i;
	int				sign;

	result = 0;
	border = (unsigned long)(FT_LONG_MAX / 10);
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	dopat(&sign, str, &i);
	while (ft_isdigit(str[i]))
	{
		if ((result > border || (result == border && (str[i] - '0') > 7))
			&& sign == 1)
			return (-1);
		else if ((result > border || (result == border && (str[i] - '0') > 8))
			&& sign == -1)
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return ((int)(result * sign));
}

void	dopat(int *sign, const char *str, size_t *i)
{
	*sign = 1;
	if (str[*i] == '-')
		*sign = -1;
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}
