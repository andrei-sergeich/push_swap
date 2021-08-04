#include "libft.h"

static int	positive_or_negative(char in, int x)
{
	if (in == 45)
		x = -x;
	return (x);
}

int	ft_atoi(const char *str)
{
	int		in;
	int		x;
	long	num;

	in = 0;
	x = 1;
	num = 0;
	while ((((str[in] > 8) && (str[in] < 14)) || str[in] == 32) && \
			str[in] != '\0')
		in++;
	if (str[in] == 43 || str[in] == 45)
		x = positive_or_negative(str[in++], x);
	if (str[in] < 48 || str[in] > 57)
		return (0);
	while ((str[in] > 47) && (str[in] < 58))
	{
		if (num > 2147483647 && x == 1)
			return (-1);
		if (num > 2147483648 && x == -1)
			return (0);
		num = num * 10 + (str[in++] - '0');
	}
	return (x * num);
}
