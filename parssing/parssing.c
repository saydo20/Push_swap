/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parssing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:28 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/27 15:59:08 by sjdia            ###   ########.fr       */
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
		if (ptr[i][j] == '+' || ptr[i][j] == '-')
			j++;
		if (ptr[i][j] == '\0')
		{
			free_split(ptr);
			full_exit(stack);
		}
		while (ptr[i][j])
		{
			if (ptr[i][j] < '0' || ptr[i][j] > '9')
			{
				free_split(ptr);
				full_exit(stack);
			}
			j++;
		}
		i++;
	}
}

char	**pars_list(char **ptr, t_stack *stack)
{
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

void	fill_stack(char **ptr, t_stack *A)
{
	int		i;
	t_list	*new;

	i = 0;
	while (ptr[i])
	{
		if (!is_valid_int(ptr[i]))
			free_ptr(ptr, i, A);
		new = creat_node(ft_atoi(ptr[i], A));
		if (!new)
			free_ptr(ptr, i, A);
		add_node_back(A, new);
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	fill_ptr(char **av, t_stack *A)
{
	int		i;
	int		j;
	char	**ptr;
	t_list	*new;

	j = 1;
	while (av[j])
	{
		if (!av[j] || av[j][0] == '\0')
			full_exit(A);
		ptr = ft_split(av[j], ' ');
		if (!ptr)
			full_exit(A);
		ptr = pars_list(ptr, A);
		fill_stack(ptr, A);
		j++;
	}
}
