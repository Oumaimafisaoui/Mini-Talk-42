#include "minitalk.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	res;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = (n * (-1));
	}
	else
	{
		res = n;
	}
	if (res > 9)
	{
		ft_putnbr_fd(res / 10, fd);
	}
	ft_putchar_fd(res % 10 + '0', fd);
}

int ft_atoi(const char *dest)
{
	int	sign;
	int 	result;
	int	i;

	i = 0;
	sign = 1;
	result = 0;

	if(*dest == 0)
		return (0);

	while (dest[i] ==  ' ' || (dest[i] >= 9 && dest[i] <= 13))
		i++;

	if(dest[i] == '+' || dest[i] == '-')
	{
		if(dest[i] == '-')
			sign *= -1;
		i++;
	}

	while(dest[i] && dest[i] <= '9' && dest[i] >= '0')
	{
		result *= 10;
		result += (dest[i] - 48);
		i++;
	}
	return (result * sign);
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, ft_strlen(s));
}

size_t	ft_strlen(const char *str)
{
	size_t index;

	index = 0;
	while(str[index] != '\0')
		index++;
	return (index);
}