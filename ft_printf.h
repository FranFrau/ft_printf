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

int		complete_conversion(int n, char *str, char *digits);
int		print_hex(int nb, char *digits);

int		ft_putnbr(int nb);

int		ptr_len(unsigned long long n);
int		ptr_print(unsigned long long num);
void	ptr_conv(unsigned long long num);

int		ft_put_unsigned_nbr(unsigned int nb);

#endif
