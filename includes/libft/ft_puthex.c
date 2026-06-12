/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:55:45 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/12 18:29:37 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned int n, char format)
{
	int		count;
	int		ret;
	char	*hex_chars;

	hex_chars = "0123456789abcdef";
	if (format == 'X')
		hex_chars = "0123456789ABCDEF";
	if (n < 16)
		return (ft_putchar(hex_chars[n]));
	count = ft_puthex(n / 16, format);
	if (count == -1)
		return (-1);
	ret = ft_puthex(n % 16, format);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
