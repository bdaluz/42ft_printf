/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 17:18:36 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/05/28 11:21:26 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	numlen(long i)
{
	unsigned int	len;

	len = 0;
	if (i <= 0)
		len = 1;
	while (i && ++len)
		i /= 10;
	return (len);
}

char	*ft_itoa(int n)
{
	long	num;
	int		len;
	char	*str;

	num = n;
	len = numlen(num);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (num == 0)
		str[0] = '0';
	if (num < 0)
		str[0] = '-';
	if (num < 0)
		num = -num;
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}
