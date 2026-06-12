/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:55:45 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/12 19:15:08 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_unsigned(unsigned int n)
{
	int		count;
	int		ret;

	if (n < 10)
		return (ft_putchar(n + '0'));
	count = ft_putnbr_unsigned(n / 10);
	if (count == -1)
		return (-1);
	ret = ft_putnbr_unsigned(n % 10);
	if (ret == -1)
		return (-1);
	return (count + ret);
}
