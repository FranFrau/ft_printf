#include "ft_printf.h"

int	complete_conversion(int n, char *str, char *digits)
{
	unsigned int	nb;
	int				i;
	char			*porcocazzo;

	i = 7;
	if (n < 0)
		nb = 4294967295 + n + 1;
	else
		nb = n;
	while (nb && str)
	{
		str[i] = digits[nb % 16];
		nb /= 16;
		i--;
	}
	porcocazzo = str;
	while (!*str)
		str++;
	str[8] = 0;
	ft_putstr(str);
	i = ft_strlen(str);
	free(porcocazzo);
	return (i);
}

int	print_hex(int nb, char *digits)
{
	char		*str;

	str = malloc(9);
	if (!str)
		return (0);
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = 0;
	}
	return (complete_conversion(nb, str, digits));
}
