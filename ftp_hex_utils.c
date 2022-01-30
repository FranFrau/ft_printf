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

int	complete_conversion_p(unsigned long n, char *str, char *digits)
{
	unsigned long long	nb;
	int					i;
	char				*porcocazzo;

	i = 7;
	if (n < 0)
		nb = 9223372036854775807 + n + 1;
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

int	print_hex_p(int nb, char *digits)
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

char	hex_digit(int v)
{
	if (v >= 0 && v < 10)
		return ('0' + v);
	else
		return ('a' + v - 10);
}

int	print_address_hex(void *p0)
{
	int			i;
	/*
	uintptr_t	p;

	p = (uintptr_t)p0;*/
	ft_putchar('0');
	ft_putchar('x');
	i = print_hex_p((long) p0, "0123456789abcdef") + 2;
	/*
	for(i = (sizeof(p) << 3) - 4; i>=0; i -= 4) {
		ft_putchar(hex_digit((p >> i) & 0xf));
	}
	return i;*/
	return (i);
	//printf("Prova: %d\n", p0);
}
