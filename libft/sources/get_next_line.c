/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/26 13:48:27 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/27 12:26:59 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

void	dop2(char *buf, char **pos, char **s, char **tmp);
void	dop1(char ***line, char *pos, char **s, char **tmp);

int	ft_check(char **line, char **s, char **pos)
{
	if (!line)
		return (-1);
	if (!*s)
	{
		*s = ft_2_strdup("");
		if (!*s)
			return (-1);
	}
	*pos = ft_2_strchr(*s, '\n');
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*s;
	char		buf[1025];
	char		*pos;
	char		*tmp;
	int			ret;

	ret = ft_check(line, &s, &pos);
	if (ret == -1)
		return (-1);
	while (pos == 0)
	{
		ret = read(fd, buf, 1024);
		if (ret == 0)
			break ;
		buf[ret] = 0;
		dop2(buf, &pos, &s, &tmp);
	}
	if (pos)
	{
		dop1(&line, pos, &s, &tmp);
		return (1);
	}
	*line = ft_2_strdup(s);
	free(s);
	return (0);
}

void	dop1(char ***line, char *pos, char **s, char **tmp)
{
	**line = ft_2_substr(*s, 0, pos - *s);
	*tmp = *s;
	*s = ft_2_substr(*s, pos - *s + 1, ft_2_strlen(*s));
	free(*tmp);
}

void	dop2(char *buf, char **pos, char **s, char **tmp)
{
	*tmp = *s;
	*s = ft_2_strjoin(*s, buf);
	free(*tmp);
	*pos = ft_2_strchr(*s, '\n');
}
