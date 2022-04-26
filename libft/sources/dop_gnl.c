#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>

size_t	ft_2_strlen(char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

char	*ft_2_strdup(char *s)
{
	char	*new;
	char	*res;

	new = malloc(ft_2_strlen(s) + 1);
	res = new;
	while (*s)
		*new++ = *s++;
	*new = 0;
	return (res);
}

char	*ft_2_strchr(char *s, char c)
{
	if (*s == c)
		return (s);
	while (*s++)
		if (*s == c)
			return (s);
	return (NULL);
}

char	*ft_2_strjoin(char *s1, char *s2)
{
	char	*new;
	char	*res;

	new = malloc(ft_2_strlen(s1) + ft_2_strlen(s2) + 1);
	res = new;
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = 0;
	return (res);
}

char	*ft_2_substr(char *s, int start, int len)
{
	char	*new;
	char	*res;

	new = malloc(len + 1);
	res = new;
	while (start--)
		s++;
	while (len-- && *s)
		*new++ = *s++;
	*new = 0;
	return (res);
}
