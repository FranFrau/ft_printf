#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "../libft/libft.h"

# define TYPES "cspdiuxX"

void	ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_strlen(const char *str);
int		lenght(int nb, int base);
int		ll_lenght(long long nb, int base);
int		other_flags(char type, va_list curr_param);
int		flag_print(char type, va_list curr_param);
int		ft_printf(const char *a, ...);
int		print_char(va_list param);
int		print_hex(int nb, char *digits);
int		ft_putnbr(int nb);
int		ft_put_unsigned_nbr(unsigned int nb);
int		print_address_hex(void *p0);

#endif
