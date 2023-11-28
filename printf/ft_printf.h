/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luyang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 19:23:02 by luyang            #+#    #+#             */
/*   Updated: 2023/11/20 19:26:18 by luyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <stdint.h>

typedef struct s_flags
{
	int	left;
	int	zero;
	int	space;
	int	plus;
	int	hash;
	int	precision;
	int	width;
	int	dot;
	int	error;
	char	type;
}				t_flags;


int	ft_put_char(int c);
int	ft_printchar(t_flags flags, int c);
int	ft_printstr(t_flags flags, char *str);
int	ft_putstr(char *str);
int	ft_printstr_left(t_flags flags, char *str);
int	ft_printstr_no_left(t_flags flags, char *str);
int	ft_formats(va_list args, const char *format);
int	ft_printf(const char *format, ...);
int	ft_print_ptr(t_flags flags, unsigned long int ptr);
void	ft_put_ptr_left(t_flags flags, unsigned long int ptr, int length);
void	ft_put_ptr_no_left(t_flags flags, unsigned long int ptr, int length);
void    ft_put_ptr(unsigned long int ptr);
int	ft_print_int(t_flags flags, long n);
int	ft_print_int_body(t_flags flags, long n);
void	ft_put_hex(unsigned int num, const char format);
int	ft_print_hex(t_flags flags, unsigned int num, const char format);
int	ft_print_hex_body(t_flags flags, unsigned int n, const char format);
int	ft_ptrlen(unsigned long int ptr);
int	ft_nbrlen(long n);
void	ft_putnbr(long n);
t_flags	ft_reset_flags(void);
t_flags	ft_set_flags(t_flags flags, const char *format);
int	ft_print_all(t_flags flags, va_list args);
int ft_padding(t_flags flags, long n, int (*f)());
int	ft_print_unsigned(t_flags flags, unsigned int n);
t_flags	ft_set_flags_wp(t_flags flags, const char *format);
t_flags	ft_flags_check_error(t_flags flags);

#endif
