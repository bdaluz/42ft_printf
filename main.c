/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 12:29:36 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/09 13:56:22 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdio.h>

void	testing(int num, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, num);
	i = 0;
	while (i < num)
	{
		printf("Num: %d\n", va_arg(ap, int));
		i++;
	}
	va_end(ap);
}

int	main(void)
{
	testing(4, 10, 11, 12, 28);
	return (0);
}
