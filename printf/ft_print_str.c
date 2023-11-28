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
	if (flags.precision < lenstr && flags.precision != 0)
	{
		while (flags.width-- > 0)
		{
			while (flags.precision-- > 0 && flags.width-- > 0)
				ft_put_char((int) *str++);
			ft_put_char(' ');
		}
	}
	else
	{
		while (flags.width-- > 0)
		{
			while (*str && flags.width-- > 0)
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
	if (flags.precision < (int)ft_strlen(str) && flags.precision != 0)
	{
		diff = flags.width - flags.precision;
		while (flags.width-- > 0)
		{
			while (diff-- > 0 && flags.width-- > 0)
				ft_put_char(' ');
			ft_put_char((int) *str++);
		}
	}
	else
	{
		diff = flags.width - ft_strlen(str);
		while (flags.width-- > 0)
		{
			while (diff-- > 0 && flags.width-- > 0)
				ft_put_char(' ');
			ft_put_char((int) *str++);
		}
	}
	return (length);	
}

int	ft_printstr(t_flags flags, char *str)
{
	int	length;


	if (!str)
		return (ft_putstr("(null)"));	
	if (!*str)
		return (0);
	length = 0;
	if (flags.width > (int)ft_strlen(str) && flags.width != 0)
	{
		if (flags.left == 1)
			length = ft_printstr_left(flags, str);
		else
			length = ft_printstr_no_left(flags, str);
	}
	else
	{
		if (flags.precision < (int)ft_strlen(str) && flags.precision != 0)
		{
			while (flags.precision-- > 0)
				length += ft_put_char(*str++);
		}
		else
			length += ft_putstr(str);
	}
	return (length);
}
