/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:50:28 by luyang            #+#    #+#             */
/*   Updated: 2023/11/21 13:50:32 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_put_char(num + '0');
		else if (format =='x')
			ft_put_char(num - 10 + 'a');
		else if (format == 'X')
			ft_put_char(num - 10 + 'A');
	}
}

int	ft_print_hex_body(t_flags flags, unsigned int n, const char format)
{
	int	length;
	int diff;

	length = 0;
	diff = 0;
	if (flags.hash)
	{
		length += ft_put_char('0');
		length += ft_put_char(format);
	}
	if (ft_ptrlen((unsigned long)n) < flags.precision)
	{
		diff = flags.precision - ft_ptrlen((unsigned long)n);
		while (diff-- > 0)
			length += ft_put_char('0');
	}
	ft_put_hex(n, format);
	length += ft_ptrlen(n);
	return (length);
}

int		ft_print_hex(t_flags flags, unsigned int num, const char format)
{
	int	length;

	length = 0;
	if (flags.left)
		length += ft_print_hex_body(flags, num, format);
	length += ft_padding(flags, num, ft_ptrlen);
	if (!flags.left)
		length += ft_print_hex_body(flags, num, format);
	return (length);
} 