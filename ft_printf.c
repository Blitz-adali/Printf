/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:15:08 by raaalali          #+#    #+#             */
/*   Updated: 2025/12/25 13:07:02 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list ap, char c)
{
	if (c == 'c')
		return (ft_printf_char(va_arg(ap, int)));
	if (c == 's')
		return (ft_printf_str(va_arg(ap, char *)));
	if (c == 'p')
		return (ft_printf_ptr(va_arg(ap, unsigned long long)));
	if (c == 'd' || c == 'i')
		return (ft_printf_nbr(va_arg(ap, int)));
	if (c == 'u')
		return (ft_printf_unsigned(va_arg(ap, unsigned int)));
	if (c == 'x')
		return (ft_printf_hex(va_arg(ap, unsigned int), 0));
	if (c == 'X')
		return (ft_printf_hex(va_arg(ap, unsigned int), 1));
	return (0);
}
int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	if (!str)
		return (-1);
	count = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (!*str)
				break ;
			if (*str == '%')
				count += write(1, "%", 1);
			else
				count += ft_format(ap, *str);
		}
		else
			count += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (count);
}
