/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:28 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/20 09:58:42 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pars_helper(char **ptr, t_stack *stack)
{
	int	i;
	int	j;

	i = 0;
	while (ptr[i])
	{
		j = 0;
		while (ptr[i][j])
		{
			if (ptr[i][j] >= '0' && ptr[i][j] <= '9')
				j++;
			else if ((ptr[i][j] == '-' || ptr[i][j] == '+') &&
				(ptr[i][j + 1] >= '0' && ptr[i][j + 1] <= '9'))
				j++;
			else
			{
				free_split(i, ptr);
				full_exit(stack);
			}
		}
		i++;
	}
}

char	**pars_list(char **ptr, t_stack *stack)
{
	int		i;
	int		j;

	if (!ptr[0])
	{
		free(ptr);
		full_exit(stack);
	}
	pars_helper(ptr, stack);
	return (ptr);
}

void	free_ptr(char **ptr, int i, t_stack *A)
{
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	full_exit(A);
}

void	fill_ptr(char **av, t_stack *A)
{
	int		i;
	int		j;
	char	**ptr;

	j = 1;
	while (av[j])
	{
		if (! av[j] || av[j][0] == '\0')
			full_exit(A);
		ptr = ft_split(av[j], ' ');
		if (!ptr)
			full_exit(A);
		ptr = pars_list(ptr, A);
		i = 0;
		while (ptr[i])
		{
			if (!is_valid_int(ptr[i]))
				free_ptr(ptr, i, A);
			add_node_back(A, creat_node(ft_atoi(ptr[i], A)));
			free(ptr[i]);
			i++;
		}
		free(ptr);
		j++;
	}
}
