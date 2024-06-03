/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:40:54 by envillan          #+#    #+#             */
/*   Updated: 2024/05/31 22:51:50 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_check_type(char c, va_list *args, int *length, int *i)
{
	if (c == 's')
		ft_string(va_arg(*args, char *), length);
	else if (c == 'd' || c == 'i')
		ft_number(va_arg(*args, int), length);
	else if (c == 'u')
		ft_unsigned_int(va_arg(*args, unsigned int), length);
	else if (c == 'x')
		ft_hexadecimal(va_arg(*args, unsigned int), length, 'x');
	else if (c == 'X')
		ft_hexadecimal(va_arg(*args, unsigned int), length, 'X');
	else if (c == 'p')
		ft_pointer(va_arg(*args, size_t), length);
	else if (c == 'c')
		ft_putchar_length(va_arg(*args, int), length);
	else if (c == '%')
		ft_putchar_length('%', length);
	else
		(*i)--;
}

int	ft_printf(const char *string, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, string);
	while (string[i] != '\0')
	{
		if (string[i] == '%')
		{
			i++;
			ft_check_type(string[i], &args, &length, &i);
			i++;
		}
		else
		{
			ft_putchar_length((char)string[i], &length);
			i++;
		}
	}
	va_end(args);
	return (length);
}
