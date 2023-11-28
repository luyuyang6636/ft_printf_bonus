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

int	ft_print_hex_body(t_flags flags, unsigned int n)
{
	
}

int		ft_print_hex(t_flags flags, unsigned int num, const char format)
{

	ft_put_hex(num, format);
	return (ft_ptrlen(num));
} 