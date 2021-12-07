#include "ft_printf.h"

int	ft_putnbr(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		count += write (1, "-", 1);
		i *= -1;
	}
	if (i > 9)
		count += ft_putnbr(i / 10);
	i = i % 10 + '0';
	count += write (1, &i, 1);
	return (count);
}
