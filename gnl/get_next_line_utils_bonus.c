#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	x;

	x = 0;
	while (s[x])
		x++;
	return (x);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*ptr;
	size_t	x;

	x = 0;
	ptr = (void *)malloc(count * size);
	if (!ptr)
		return (NULL);
	while (x < count * size)
	{
		ptr[x] = 0;
		x++;
	}
	return ((void *)ptr);
}

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l;
	size_t	x;

	x = 0;
	l = ft_strlen(s1);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (NULL);
	while (x < l)
	{
		str[x] = s1[x];
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	x;

	x = 0;
	while (src[x])
	{
		dst[x] = src[x];
		x++;
	}
	dst[x] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	x;
	size_t	y;

	if (!s1 || !s2)
		return (NULL);
	x = 0;
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	y = 0;
	while (s1[y])
		str[x++] = s1[y++];
	y = 0;
	while (s2[y])
		str[x++] = s2[y++];
	str[x] = '\0';
	free ((void *)s1);
	return (str);
}
