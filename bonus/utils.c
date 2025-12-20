/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:14 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/19 11:24:24 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_words(const char *s, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			counter++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (counter);
}

char	*mft_strdup(char *s, size_t start, size_t end)
{
	char	*ptr;
	size_t	i;

	ptr = malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < end - start)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*free_split(int index, char **s)
{
	int		j;

	j = 0;
	while (j <= index)
	{
		free(s[j]);
		j++;
	}
	free(s);
	return (NULL);
}

char	**fill(char **ptr, char *s, char c)
{
	size_t	i;
	size_t	k;
	size_t	y;

	i = 0;
	k = 0;
	y = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			k = i;
			while (s[k] && s[k] != c)
				k++;
			ptr[y] = mft_strdup((char *)s, i, k);
			if (!ptr[y])
				return (free_split(y, ptr), NULL);
			y++;
			i = k;
		}
		else
			i++;
	}
	ptr[y] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	return (fill(ptr, (char *)s, c));
}
