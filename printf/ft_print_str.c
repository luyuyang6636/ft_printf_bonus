/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 18:57:58 by luyang            #+#    #+#             */
/*   Updated: 2023/11/24 18:58:04 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_put_char(str[i]);
		i++;
	}
	return (ft_strlen(str));
}

int	ft_printstr_left(t_flags flags, char *str)
{
	int	lenstr;
	int	length;

	length = flags.width;
	lenstr = ft_strlen(str);
	if (flags.precision < lenstr)
	{
		while (flags.width--)
		{
			while (flags.precision-- > 0 && flags.width--)
				ft_put_char((int) *str++);
			ft_put_char(' ');
		}
	}
	else
	{
		while (flags.width--)
		{
			while (*str && flags.width--)
				ft_put_char((int) *str++);
			ft_put_char(' ');
		}
	}
	return (length);	
}

int	ft_printstr_no_left(t_flags flags, char *str)
{
	int	diff;
	int	length;

	length = flags.width;
	if (flags.precision < (int)ft_strlen(str))
	{
		diff = flags.width - flags.precision;
		while (flags.width--)
		{
			while (diff-- > 0 && flags.width--)
				ft_put_char(' ');
			ft_put_char((int) *str++);
		}
	}
	else
	{
		diff = flags.width - ft_strlen(str);
		while (flags.width--)
		{
			while (diff-- && flags.width--)
				ft_put_char(' ');
			ft_put_char((int) *str++);
		}
	}
	return (length);	
}

int	ft_printstr(t_flags flags, char *str)
{
	int	length;

	length = 0;
	if (flags.width > (int)ft_strlen(str) && flags.width)
	{
		if (flags.left)
			length = ft_printstr_left(flags, str);
		else
			length = ft_printstr_no_left(flags, str);
	}
	else
	{
		if (flags.precision < (int)ft_strlen(str) && flags.precision)
		{
			while (flags.precision--)
				length += ft_put_char(*str++);
		}
		else
			length += ft_putstr(str);
	}
	return (length);
}
