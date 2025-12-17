/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:02:59 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/17 13:27:48 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_smallest_in_a(t_stack *A)
{
	t_list	*tmp;
	int		min;
	int		pos;
	int		i;

	tmp = A->head;
	min = *(tmp->content);
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (*(tmp->content) < min)
		{
			min = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

void	sort_5(t_stack *A, t_stack *B)
{
	int	pos;

	pos = find_smallest_in_a(A);
	push_the_smallest_to_b(A, B, pos);
	pos = find_smallest_in_a(A);
	push_the_smallest_to_b(A, B, pos);
	sort_3(A);
	pa(A, B);
	pa(A, B);
}

void	push_the_smallest_to_b(t_stack *A, t_stack *B, int pos)
{
	int	size;
	int	r;

	size = stack_size(A);
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			ra(A);
	}
	else
	{
		r = size - pos;
		while (r-- > 0)
			rra(A);
	}
	pb(A, B);
}

void	full_exit(t_stack *stack)
{
	write(1, "Error!\n", 7);
	stack_clear(stack);
	exit(1);
}
