/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:50:37 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/10 16:07:10 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_test(int n)
{
	char			str[10];
	long			num;
	unsigned int	i;
	int				count;

	num = n;
	count = 0;
	if (num == 0)
	{
		count += write(1, "0", 1);
		return (0);
	}
	if (num < 0)
	{
		count += write(1, "-", 1);
		num = -num;
	}
	i = 0;
	while (num)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
		count += write(1, &str[--i], 1);
	return (count);
}


int	ft_formatter(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_test(va_arg(*ap, int)));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			count += ft_formatter(*(++fmt), &ap);
			fmt++;
		}
		else
			count += write(1, fmt++, 1);
	}
	va_end(ap);
	return (count);
}
