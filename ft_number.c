/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_number.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:29:16 by envillan          #+#    #+#             */
/*   Updated: 2024/07/04 11:43:11 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_min(int n)
{
	(void)n;
	if (write(1, "-2147483648", 11) != 11)
		return (-1);
	return (11);
}

int	ft_print_number(int n)
{
	int	size;

	size = 0;
	if (n == -2147483648)
		return (int_min(n));
	if (n < 0 && ++size)
	{
		if (ft_print_char('-') != 1)
			return (-1);
		n = -n;
	}
	if (n > 9)
	{
		size += ft_print_number(n / 10);
		if (size == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_print_char(('0' + n)) == -1)
			return (-1);
		size++;
	}
	return (size);
}

unsigned int	ft_print_unsigned(unsigned int n)
{
	int	size;

	size = 0;
	if (n > 9)
	{
		size = ft_print_unsigned(n / 10);
		if (size == -1)
			return (-1);
		n = n % 10;
	}
	if (n <= 9)
	{
		if (ft_print_char(('0' + n)) == -1)
			return (-1);
		size++;
	}
	return (size);
}
