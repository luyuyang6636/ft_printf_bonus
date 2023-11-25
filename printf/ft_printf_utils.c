#include "ft_printf.h"

int ft_padding(t_flags flags, long n, int (*f)(void *))
{
    int count;
    int diff;

    count = 0;
    diff = 0;
    if ((flags.plus || flags.space) && n >= 0)
        count++;
    else if (n < 0)
    {
        count++;
        n *= -1;
    }
    if (flags.precision > f(n))
        count += flags.precision;
    diff = flags.precision - count;
    while (count < flags.width)
    {
        if (flags.zero && !flags.left)
            ft_put_char('0');
        else
            ft_put_char(' ');
    }
    return (count);
}