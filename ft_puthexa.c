#include "ft_printf.h"

int	ft_puthexa(unsigned long n, char *base)
{
	static int	count;
	char		to_print;

	count = 0;
	if (n > 15)
		ft_puthexa(n / 16, base);
	to_print = base[n % 16];
	count += write(1, &to_print, 1);
	return (count);
}
