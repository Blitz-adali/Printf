/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raaalali <raad.ali@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 19:13:46 by raaalali          #+#    #+#             */
/*   Updated: 2025/12/18 19:13:51 by raaalali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_nbr(int n)
{
	int		count;
	char	c;

	count = 0;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	if (n < 0)
	{
		count += write(1, "-", 1);
		n *= -1;
	}
	if (n < 10)
	{
		c = n + '0';
		count += write(1, &c, 1);
	}
	else
	{
		count += ft_printf_nbr(n / 10);
		count += ft_printf_nbr(n % 10);
	}
	return (count);
}
