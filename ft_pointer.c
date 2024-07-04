/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:07:31 by envillan          #+#    #+#             */
/*   Updated: 2024/07/03 13:12:54 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_ptr(unsigned long long ptr)
{
	int	length;

	length = 0;
	while (ptr > 0)
	{
		length++;
		ptr /= 16;
	}
	return (length);
}

static void	ft_pointer(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_pointer(ptr / 16);
		ft_pointer(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_print_char(ptr + '0');
		else
			ft_print_char(ptr - 10 + 'a');
	}
}

int	ft_print_pointer(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		size += ft_print_string("(nil)");
	else
	{
		size += ft_print_string("0x");
		ft_pointer(ptr);
		size += ft_length_ptr(ptr);
	}
	return (size);
}
