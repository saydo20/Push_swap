/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:28 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 09:56:13 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**pars_list(char *str)
{
	char	**ptr;
	int		i;
	int		j;

	i = 0;
	ptr = ft_split(str, ' ');
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] >= '0' && ptr[i][j] <= '9')
				j++;
			else if ((ptr[i][j] == '-' || ptr[i][j] == '+') &&
				(ptr[i][j + 1] >= '0' && ptr[i][j + 1] <= '9'))
				j+=2;
			else
			{
				printf("error!\n");
				exit(1);
			}
		}
		i++;
	}
	return (ptr);
}
