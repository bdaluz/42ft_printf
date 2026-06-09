/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/22 15:52:44 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/05/23 14:33:06 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int		nb;
	short	sign;

	nb = 0;
	sign = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if (*nptr == '-')
	{
		sign = -sign;
		nptr++;
		if (*nptr == '+')
			return (0);
	}
	if (*nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		nb = nb * 10 + (*nptr - '0');
		nptr++;
	}
	return (nb * sign);
}
