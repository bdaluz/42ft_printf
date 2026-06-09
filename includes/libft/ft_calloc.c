/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/23 11:08:18 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/05/25 10:13:40 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	sz;
	void	*ptr;

	sz = nmemb * size;
	if (nmemb != 0 && size > (sz / nmemb))
		return (NULL);
	ptr = malloc(sz);
	if (ptr != NULL)
		ft_bzero(ptr, sz);
	return (ptr);
}
