/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgwin <tgwin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 19:09:23 by vbrazhni          #+#    #+#             */
/*   Updated: 2022/04/26 21:08:51 by tgwin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	dopfw(char *word, char **words, size_t i);

static size_t	ft_count_words(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			words++;
			while (*s && *s != c)
				s++;
		}
	}
	return (words);
}

static char	*ft_get_word(char *word, char c)
{
	char	*start;

	start = word;
	while (*word && *word != c)
		word++;
	*word = '\0';
	return (ft_strdup(start));
}

static char	**ft_get_words(char *s, char c, size_t words_count)
{
	char	**words;
	char	*word;
	size_t	i;

	i = 0;
	words = (char **)ft_memalloc(sizeof(char *) * (words_count + 1));
	if (words)
	{
		while (i < words_count)
		{
			while (*s == c)
				s++;
			if (*s)
			{
				word = ft_get_word(s, c);
				dopfw(word, words, i);
				words[i++] = word;
				s += (ft_strlen(word) + 1);
			}
		}
		words[i] = NULL;
	}
	return (words);
}

void	dopfw(char *word, char **words, size_t i)
{
	if (!word)
	{
		while (i--)
			ft_strdel(&(words[i]));
		free(*words);
	}
}

char	**ft_strsplit(char const *s, char c)
{
	char	**words;
	char	*line;

	line = ft_strdup((char *)s);
	if (!s || !line)
		return (NULL);
	words = ft_get_words(line, c, ft_count_words(line, c));
	free(line);
	return (words);
}
