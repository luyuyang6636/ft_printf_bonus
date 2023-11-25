/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:06:02 by luyang            #+#    #+#             */
/*   Updated: 2023/11/24 13:06:03 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	ft_reset_flags(void)
{
	t_flags	flags;

	flags.left = 0;
	flags.zero = 0;
	flags.plus = 0;
	flags.space = 0;
	flags.width = 0;
	flags.type = 0;
	flags.precision = 0;
	return (flags);
}

t_flags	ft_set_flags(t_flags flags, const char *format)
{
	if (*format == '-')
		flags.left = 1;
	else if (*format == '0')
		flags.zero = 1;
	else if (*format == ' ')
		flags.space = 1;
	else if (*format == '+')
		flags.plus = 1;
	else if (*format == '#')
		flags.hash = 1;
	if (flags.left)
		flags.zero = 0;
	if (flags.plus)
		flags.space = 0;
	else if (*format == '.' || (*format >= '1' && *format <='9'))
	{
		if (*format >= '1' && *format <='9')
			flags.width = ft_atoi(format);
		while (*format >= '0' && *format <= '9')
			format++;
		if (*format == '.')
			flags.precision = ft_atoi(++format);
		return (flags);
	}
	return (flags);
}