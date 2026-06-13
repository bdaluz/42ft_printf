/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:55:45 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/12 20:43:11 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex_long(unsigned long n, char format)
{
	int		count;
	int		ret;
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
	if (format == 'X')
		hex_chars = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar(hex_chars[n]));
	count = ft_puthex_long(n / 16, format);
	if (count == -1)
		return (-1);
	ret = ft_puthex_long(n % 16, format);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
