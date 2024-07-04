/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 12:18:57 by envillan          #+#    #+#             */
/*   Updated: 2024/07/03 12:25:46 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_length_hex(unsigned int num)
{
	int	length;

	length = 0;
	while (num != 0)
	{
		length++;
		num /= 16;
	}
	return (length);
}

static void	ft_hex(unsigned int num, const char c)
{
	if (num >= 16)
	{
		ft_hex(num / 16, c);
		ft_hex(num % 16, c);
	}
	else
	{
		if (num < 10)
			ft_print_char(num + '0');
		else
		{
			if (c == 'x')
				ft_print_char(num - 10 + 'a');
			if (c == 'X')
				ft_print_char(num - 10 + 'A');
		}
	}
}

int	ft_print_hex(unsigned int num, const char c)
{
	if (num == 0)
		return (ft_print_char('0'));
	else
		ft_hex(num, c);
	return (ft_length_hex(num));
}
