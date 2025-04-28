#include "ft_printf.h"

int	printf_char(int c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_perc(void)
{
	write (1, "%", 1);
	return (1);
}

int	printf_str(char *str)
{
	int	ct;

	ct = 0;
	if (str == NULL)
		return (-1);
	while (str[ct])
	{
		write(1, &str[ct], 1);
		ct++;
	}
	return (ct);
}

int	count_int(int n)
{
	long	nn;
	size_t	ct;

	nn = n;
	ct = 0;
	if (nn < 0)
	{
		nn *= -1;
		ct++;
	}
	while (nn > 9)
	{
		nn /= 10;
		ct++;
	}
	if (nn >= 0 && nn <= 9)
		ct++;
	return (ct);
}

int	printf_putnbr(int n)
{
	char	nc;
	long	nn;
	int		ct;

	ct = 0;
	nn = n;
	if (nn < 0)
	{
		ct += printf_char('-');
		nn *= -1;
	}
	if (nn > 9)
		ct += printf_putnbr(nn / 10);
	nc = (nn % 10) + 48;
	ct += printf_char(nc);
	return (ct);
}
