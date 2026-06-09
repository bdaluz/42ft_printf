/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/28 13:31:13 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/05/28 13:49:18 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char			str[10];
	long			num;
	unsigned int	i;

	num = n;
	if (num == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	i = 0;
	while (num)
	{
		str[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
		write(fd, &str[--i], 1);
	return ;
}
