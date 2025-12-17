/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:43:03 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 10:54:42 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_stack *A)
{
	int	a;
	int	b;
	int	c;

	a = *(A->head->content);
	b = *(A->head->next->content);
	c = *(A->head->next->next->content);
	if (a > b && a > c)
		ra(A);
	a = *(A->head->content);
	b = *(A->head->next->content);
	c = *(A->head->next->next->content);
	if (b > a && b > c)
		rra(A);
	a = *(A->head->content);
	b = *(A->head->next->content);
	if (a > b)
		sa(A);
}
int    find_smallest_in_a(t_stack *A)
{
    t_list  *tmp;
	int	min;
	int	pos;
	int	i;

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

int		find_pos_max(t_stack *stack)
{
	t_list  *tmp;
	int	max;
	int	pos;
	int	i;

	tmp = stack->head;
    max = *(tmp->content);
    pos = 0;
    i = 0;
    while (tmp)
    {
        if (*(tmp->content) > max)
        {
            max = *(tmp->content);
            pos = i;
        }
        tmp = tmp->next;
        i++;
    }
	return (pos);
}

int		find_max(t_stack *stack)
{
	t_list  *tmp;
	int	max;
	int	i;

	tmp = stack->head;
    max = *(tmp->content);
    i = 0;
    while (tmp)
    {
        if (*(tmp->content) > max)
            max = *(tmp->content);
        tmp = tmp->next;
        i++;
    }
	return (max);
}

void	push_the_smallest_to_b(t_stack *A, t_stack *B, int pos)
{
    int size = stack_size(A);
    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ra(A);
    }
    else
    {
        int r = size - pos;
        while (r-- > 0)
            rra(A);
    }
    pb(A, B);
}

void	sort_5(t_stack *A, t_stack *B)
{
	int pos;

	pos = find_smallest_in_a(A);
	push_the_smallest_to_b(A, B, pos);
	pos = find_smallest_in_a(A);
	push_the_smallest_to_b(A, B, pos);
	sort_3(A);
	pa(A, B);
	pa(A, B);
}

int		find_pos(t_stack *stack, int number)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = stack->head;
	while (tmp)
    {
        if (*(tmp->content) == number)
            break;
        pos++;
		tmp = tmp->next;
    }
	return (pos);
}

void	put_chunk(t_stack *A, t_stack *B, int start, int end)
{
	t_list	*tmp;

	tmp = A->head;
	while(tmp)
	{
		if(tmp->rank >= start && tmp->rank < end)
		{
			while(tmp->rank != A->head->rank)
			if(find_pos(A, *tmp->content) < A->size / 2)
				ra(A);
			else
				rra(A);
			pb(A, B);
			tmp = A->head;
		}
		else
			tmp = tmp->next;
	}
}

void	sort_large(t_stack *A, t_stack *B)
{
	int		chunk_size;
	int		min;
	int		max;
	int		pos;

	if(A->size <= 100)
		chunk_size = 3;
	else 
		chunk_size = 45;
	min = 0;
	max = chunk_size;
	while(A->head)
	{
		put_chunk(A, B, min, max);
		min += chunk_size;
		max += chunk_size;
	}
	while(B->head)
	{
		pos = find_pos_max(B);
		max = find_max(B);
		if(pos <= B->size / 2)
		while(*B->head->content != max)
			rb(B);
		else
			rrb(B);
		pa(A, B);
	}

}

void	sort(t_stack *A, t_stack *B)
{
	if(A->size == 3)
		sort_3(A);
	else if (A->size == 5)
		sort_5(A, B);
	else 
		sort_large(A, B);

}
