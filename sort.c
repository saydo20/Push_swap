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

void	sort(t_stack *A, t_stack *B)
{
	
	while (A->size > 3)
		pb(A, B);
}
