#include "ft_printf.h"

int	print_char(va_list param)
{
	char	buffer;

	buffer = va_arg(param, int);
	ft_putchar(buffer);
	return (1);
}
