/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:43:03 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/17 14:59:06 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos(t_stack *stack, int number)
{
	t_list	*tmp;
	int		pos;

	pos = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (*(tmp->content) == number)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	put_chunk(t_stack *A, t_stack *B, int start, int end)
{
	t_list	*tmp;

	tmp = A->head;
	while (tmp)
	{
		if (tmp->rank >= start && tmp->rank < end)
		{
			while (tmp->rank != A->head->rank)
			{
				if (find_pos(A, *tmp->content) < A->size / 2)
					ra(A);
				else
					rra(A);
			}
			pb(A, B);
			if (B->head->rank <= (start + end) / 2)
				rb(B);
			tmp = A->head;
		}
		else
			tmp = tmp->next;
	}
}

void	push_back_to_b(t_stack *A, t_stack *B)
{
	int		max;
	int		pos;

	while (B->head)
	{
		max = find_max(B);
		pos = find_pos_max(B);
		while (*B->head->content != max)
		{
			if (pos <= B->size / 2)
				rb(B);
			else
				rrb(B);
		}
		pa(A, B);
	}
}

void	sort_large(t_stack *A, t_stack *B)
{
	int		chunk_size;
	int		min;
	int		max;

	if (A->size <= 100)
		chunk_size = A->size / 5;
	else
		chunk_size = A->size / 11;
	min = 0;
	max = chunk_size;
	while (A->head)
	{
		put_chunk(A, B, min, max);
		min += chunk_size;
		max += chunk_size;
	}
	push_back_to_b(A, B);
}
