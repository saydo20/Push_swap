/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:28 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/17 16:21:58 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	**pars_list(char *str, t_stack *stack)
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
				j += 2;
			else
			{
				free_split(i, ptr);
				full_exit(stack);
			}
		}
		i++;
	}
	return (ptr);
}

void	fill_ptr(char **av, t_stack *A)
{
	int		i;
	int		j;
	char	**ptr;

	j = 1;
	while (av[j])
	{
		ptr = pars_list(av[j], A);
		i = 0;
		while (ptr[i])
		{
			add_node_back(A, creat_node(ft_atoi(ptr[i], A)));
			free(ptr[i]);
			i++;
		}
		free(ptr);
		j++;
	}
}
