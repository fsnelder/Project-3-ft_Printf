#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

int	ft_putchar(int c);
int	ft_putnbr(long int i);
int	ft_puthexa(unsigned long n, char *base);
int	ft_putusd(unsigned int n, char *base);
int	ft_putstr(char *s);
int	ft_printf(const char *str, ...);

#endif
