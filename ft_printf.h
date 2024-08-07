/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: envillan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 22:16:31 by envillan          #+#    #+#             */
/*   Updated: 2024/07/04 11:26:36 by envillan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int				ft_print_char(int c);
int				ft_printf(const char *str, ...);
int				ft_print_string(char *str);
int				ft_print_number(int n);
unsigned int	ft_print_unsigned(unsigned int n);
int				ft_print_hex(unsigned int num, const char c);
int				ft_print_pointer(unsigned long long ptr);

#endif
