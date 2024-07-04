/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:40:54 by envillan          #+#    #+#             */
/*   Updated: 2024/07/03 13:07:39 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_check_type(va_list arg, const char type)
{
	int	size;

	size = 0;
	if (type == 's')
		size += ft_print_string(va_arg(arg, char *));
	else if (type == 'd' || type == 'i')
		size += ft_print_number(va_arg(arg, int));
	else if (type == 'u')
		size += ft_print_unsigned(va_arg(arg, unsigned int));
	else if (type == 'x' || type == 'X')
		size += ft_print_hex(va_arg(arg, unsigned int), type);
	else if (type == 'p')
		size += ft_print_pointer(va_arg(arg, unsigned long long));
	else if (type == 'c')
		size += ft_print_char(va_arg(arg, int));
	else if (type == '%')
		size += ft_print_char('%');
	return (size);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			length += ft_check_type(arg, str[i + 1]);
			i += 2;
		}
		else
		{
			length += ft_print_char(str[i]);
			i++;
		}
	}
	va_end(arg);
	return (length);
}
