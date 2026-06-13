/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/12 15:55:45 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/12 21:51:27 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	int		count;
	int		ret;

	if (!ptr)
		return (ft_putstr("(nil)"));
	count = ft_putstr("0x");
	if (count == -1)
		return (-1);
	ret = ft_puthex_long((unsigned long)ptr, 'x');
	if (ret == -1)
		return (-1);
	return (count + ret);
}
