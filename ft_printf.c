#include "ft_printf.h"

static int	check_arg(va_list arg, const char *str)
{
	if (*str == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (*str == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (*str == 'd')
		return (ft_putnbr(va_arg(arg, int)));
	else if (*str == 'i')
		return (ft_putnbr(va_arg(arg, int)));
	else if (*str == 'p')
	{
		write (1, "0x", 2);
		return (ft_puthexa(va_arg(arg, unsigned long), "0123456789abcdef") + 2);
	}
	else if (*str == 'u')
		return (ft_putusd(va_arg(arg, unsigned int), "0123456789"));
	else if (*str == 'x')
		return (ft_puthexa(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (*str == 'X')
		return (ft_puthexa(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (*str == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	va_start (arg, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += check_arg(arg, &str[i]);
		}
		else
			count += write(1, &str[i], 1);
		i++;
	}
	va_end (arg);
	return (count);
}
