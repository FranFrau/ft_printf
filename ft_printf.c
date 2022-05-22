/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffrau <ffrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 01:11:30 by ffrau             #+#    #+#             */
/*   Updated: 2022/05/23 01:11:31 by ffrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	other_flags(char type)
{
	if (type > 'A' && type < 'E')
	{
		ft_putchar('%');
		ft_putchar(type);
	}
	else if (type > 'H' && type <= 'Z')
	{
		ft_putchar('%');
		ft_putchar(type);
	}
	else
		ft_putchar('%');
	return (1);
}

int	flag_print(const char type, va_list curr_param)
{
	if (type == 'c')
		return (print_char(curr_param));
	else if (type == 's')
		return (ft_putstr(va_arg(curr_param, char *)));
	else if (type == 'p')
		return (ptr_print(va_arg(curr_param, unsigned long long)));
	else if (type == 'd')
		return (ft_putnbr(va_arg(curr_param, int)));
	else if (type == 'i')
		return (ft_putnbr(va_arg(curr_param, int)));
	else if (type == 'u')
		return (ft_put_unsigned_nbr(va_arg(curr_param, unsigned int)));
	else if (type == 'x' || type == 'X')
		return (ft_print_hex(va_arg(curr_param, unsigned int), type));
	else if (type == '%')
		ft_putchar('%');
	else
		return (other_flags(type));
	return (1);
}

int	ft_printf(const char *a, ...)
{
	va_list	param_list;
	int		i;
	int		counter;

	counter = 0;
	i = 0;
	va_start(param_list, a);
	while (a[i])
	{
		if (a[i] == '%')
		{
			i++;
			counter += flag_print(a[i], param_list);
			i++;
		}
		if (!a[i])
			return (counter);
		if (a[i] != '%')
		{
			counter++;
			ft_putchar(a[i]);
			i++;
		}
	}
	return (counter);
}
