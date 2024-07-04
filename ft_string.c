/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:26:07 by envillan          #+#    #+#             */
/*   Updated: 2024/07/04 11:39:24 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	if (write(1, &c, 1) != 1)
		return (-1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	size;

	size = 0;
	if (str == 0)
		return (ft_print_string("(null)"));
	while (str[size])
		size += ft_print_char(str[size]);
	return (size);
}
