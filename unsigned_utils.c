#include "ft_printf.h"

int	printf_uchar(unsigned int c)
{
	write(1, &c, 1);
	return (1);
}

int	printf_unsigned(unsigned int un)
{
	int				ct;
	unsigned int	nc;

	ct = 0;
	if (un > 9)
		ct += printf_unsigned(un / (unsigned int)10);
	nc = (un % (unsigned int)10) + (unsigned int)48;
	ct += printf_uchar(nc);
	return (ct);
}

int	printf_hexa(unsigned long n, char x)
{
	char	*basis;
	int		ct;
	int		last_digit;

	ct = 0;
	if (x == 'x')
		basis = "0123456789abcdef";
	else
		basis = "0123456789ABCDEF";
	if (n >= 16)
		ct += printf_hexa(n / 16, x);
	last_digit = n % 16;
	ct += 1;
	write(1, &basis[last_digit], 1);
	return (ct);
}

int	printf_pointer(void *p)
{
	int	ct;

	ct = 0;
	if (printf_str("0x") == -1)
		return (-1);
	ct += 2;
	ct += printf_hexa((unsigned long)p, 'x');
	return (ct);
}
