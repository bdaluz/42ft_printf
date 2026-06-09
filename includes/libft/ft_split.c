/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bda-luz- <bda-luz-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/25 18:47:19 by bda-luz-          #+#    #+#             */
/*   Updated: 2026/06/03 12:06:20 by bda-luz-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	free_all(char **str, size_t i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

static size_t	wrdlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	count_words(char const *str, char c)
{
	size_t	i;
	size_t	is_new_word;

	i = 0;
	is_new_word = 1;
	while (*str)
	{
		if (*str != c && is_new_word)
		{
			is_new_word = 0;
			i++;
		}
		else if (*str == c)
			is_new_word = 1;
		str++;
	}
	return (i);
}

static size_t	split_aux(char **strs, char const *s, char const c)
{
	size_t	i;
	size_t	wlen;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			wlen = wrdlen(s, c);
			strs[i] = ft_substr(s, 0, wlen);
			if (!strs[i])
			{
				free_all(strs, i);
				return (0);
			}
			i++;
			s += wlen;
		}
	}
	strs[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char		**strs;
	size_t		cnt_words;

	if (!s)
		return (NULL);
	cnt_words = count_words(s, c);
	strs = malloc(sizeof(char *) * (cnt_words + 1));
	if (!strs)
		return (NULL);
	if (!split_aux(strs, s, c))
		return (NULL);
	return (strs);
}
