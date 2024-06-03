/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:16:31 by envillan          #+#    #+#             */
/*   Updated: 2024/05/31 22:54:54 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

void	ft_putchar_length(char c, int *length);
void	ft_string(char *args, int *length);

void	ft_number(int number, int *lenght);
void	ft_hexadecimal(unsigned int u, int *length, char c);
void	ft_unsigned_int(unsigned int u, int *length);
void	ft_pointer(size_t pointer, int *length);

int		ft_printf(const char *string, ...);

#endif
