/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:10:58 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/01 11:21:59 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	size_t			src_len;
	size_t			dest_len;
	size_t			in_size;

	src_len = ft_strlen(src);
	dest_len = 0;
	while (dst[dest_len] && dest_len < size)
		dest_len++;
	if (size <= dest_len)
		return (size + src_len);
	i = 0;
	in_size = size - 1 - dest_len;
	while (src[i] && i < in_size)
	{
		dst[dest_len + i] = src[i];
		i++;
	}
	dst[dest_len + i] = '\0';
	return (dest_len + src_len);
}
