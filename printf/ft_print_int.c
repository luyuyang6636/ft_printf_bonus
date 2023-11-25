/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 20:56:20 by luyang            #+#    #+#             */
/*   Updated: 2023/11/20 21:18:00 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	ft_print_int(long n)
{
	ft_putnbr(n);
	return (ft_nbrlen(n));
}

void	ft_putnbr(long n)
{
		if (n < 0)
	{
		ft_printchar('-');
		n *= -1;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		ft_printchar(n + '0');
}

/*int	ft_print_unsigned(unsigned int n)
{
	if (n > 9)
	{
		ft_print_unsigned(n / 10);
		ft_print_unsigned(n % 10);
	}
	else
		ft_printchar(n + '0');
}*/