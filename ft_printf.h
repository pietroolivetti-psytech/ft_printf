#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...)__attribute__((format(printf, 1, 2)));
int		printf_char(int c);
int		printf_perc(void);
int		not_in_spec(char c);
void	error_msg(void);
int		printf_str(char *str);
int		count_int(int n);
int		printf_putnbr(int n);
int		printf_unsigned(unsigned int un);
int		printf_uchar(unsigned int c);
int		printf_hexa(unsigned long n, char x);
int		printf_pointer(void *p);

#endif
