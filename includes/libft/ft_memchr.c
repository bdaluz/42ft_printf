/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 15:12:38 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/05/21 15:59:43 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	ch;

	i = 0;
	p = (unsigned char *)s;
	ch = c;
	while (i < n)
	{
		if (*p == ch)
			return (p);
		p++;
		i++;
	}
	return (0);
}
