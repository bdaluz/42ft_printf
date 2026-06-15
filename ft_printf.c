/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 15:50:37 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/15 13:03:55 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_formatter(char c, va_list *ap)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(*ap, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(*ap, char *)));
	else if (c == 'p')
		return (ft_putptr((void *)va_arg(*ap, unsigned long)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	else if (c == 'u')
		return (ft_putnbr_unsigned(va_arg(*ap, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (ft_puthex(va_arg(*ap, unsigned int), c));
	else if (c == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	va_start(ap, fmt);
	count = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			ret = ft_formatter(*(++fmt), &ap);
		else
			ret = ft_putchar(*fmt);
		if (ret == -1)
		{
			va_end(ap);
			return (-1);
		}
		count += ret;
		fmt++;
	}
	va_end(ap);
	return (count);
}
