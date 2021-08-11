#include "get_next_line_bonus.h"

char	*ft_new_line_checker(char *s)
{
	int		x;

	x = 0;
	if (!s)
		return (0);
	while (s[x])
	{
		if (s[x] == '\n')
			return ((char *)s + x);
		x++;
	}
	return (NULL);
}

int	ft_checker_mallocer(int fd, char **line, char **buf)
{
	if ((read(fd, NULL, 0) < 0) || !line || BUFFER_SIZE <= 0)
		return (-1);
	*buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	return (0);
}

char	*ft_sump_checker(char **sump, char **line)
{
	char	*p_nline;

	p_nline = NULL;
	if (*sump)
	{
		p_nline = ft_new_line_checker(*sump);
		if (p_nline)
		{
			*p_nline = '\0';
			*line = ft_strdup(*sump);
			ft_strcpy(*sump, ++p_nline);
		}
		else
		{
			*line = ft_strdup(*sump);
			free(*sump);
			*sump = NULL;
		}
	}
	else
		*line = ft_calloc(sizeof(char), 1);
	return (p_nline);
}

int	get_next_line(int fd, char **line)
{
	static char	*sump[OPEN_MAX];
	char		*buf;
	char		*p_nline;
	int			qbr;

	p_nline = NULL;
	qbr = 1;
	if (ft_checker_mallocer(fd, line, &buf) < 0)
		return (-1);
	p_nline = ft_sump_checker(&sump[fd], line);
	while (!p_nline && qbr > 0)
	{
		qbr = read(fd, buf, BUFFER_SIZE);
		buf[qbr] = '\0';
		p_nline = ft_new_line_checker(buf);
		if (p_nline)
		{
			*p_nline = '\0';
			sump[fd] = ft_strdup(++p_nline);
		}
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	return (qbr && sump[fd]);
}
