#include "ft_printf.h"

int	ft_putusd(unsigned int n, char *base)
{
	int			count;
	char		to_print;

	count = 0;
	if (n > 9)
		count += ft_putusd(n / 10, base);
	to_print = base[n % 10];
	count += write(1, &to_print, 1);
	return (count);
}
