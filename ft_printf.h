/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:15:21 by raaalali          #+#    #+#             */
/*   Updated: 2025/12/18 19:15:22 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int	ft_printf(const char *str, ...);
int	ft_format(va_list ap, char c);
int	ft_printf_char(char c);
int	ft_printf_str(char *str);
int	ft_printf_ptr(unsigned long long ptr);
int	ft_printf_nbr(int n);
int	ft_printf_unsigned(unsigned int n);
int	ft_printf_hex(unsigned int n, int uppercase);
#endif