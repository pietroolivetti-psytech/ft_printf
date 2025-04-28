#include "ft_printf.h"

static int	check_print(va_list args, const char *format)
{
	if (*format == 'c')
		return (printf_char(va_arg(args, int)));
	else if (*format == '%')
		return (printf_perc());
	else if (*format == 's')
		return (printf_str(va_arg(args, char *)));
	else if (*format == 'd' || *format == 'i')
		return (printf_putnbr(va_arg(args, int)));
	else if (*format == 'u')
		return (printf_unsigned(va_arg(args, unsigned int)));
	else if (*format == 'x' || *format == 'X')
		return (printf_hexa(va_arg(args, unsigned long), *format));
	else if (*format == 'p')
		return (printf_pointer(va_arg(args, void *)));
	return (-1);
}

int	handle_format(va_list args, const char **format)
{
	int	tct;

	tct = check_print(args, ++(*format));
	if (tct == -1)
		return (-1);
	return (tct);
}

int	ft_printf(const char *format, ...)
{
	int		ct;
	int		tct;
	va_list	args;

	va_start(args, format);
	ct = 0;
	while (*format)
	{
		if (*format == '%')
		{
			tct = handle_format(args, &format);
			if (tct == -1)
				return (-1);
			ct += tct;
		}
		else
		{
			printf_char(*format);
			ct++;
		}
		format++;
	}
	va_end(args);
	return (ct);
}
