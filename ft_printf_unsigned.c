/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:13:59 by raaalali          #+#    #+#             */
/*   Updated: 2025/12/18 19:14:01 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_unsigned(unsigned int n)
{
	int		count;
	char	c;

	count = 0;
	if (n < 10)
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	else
	{
		count += ft_printf_unsigned(n / 10);
		count += ft_printf_unsigned(n % 10);
	}
	return (count);
}
