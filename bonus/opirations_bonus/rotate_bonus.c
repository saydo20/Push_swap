/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:33 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 09:52:34 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker.h"

void	ra(t_stack *A)
{
	t_list	*first;
	t_list	*last;

	if (!A->head || !A->head->next)
		return ;
	first = A->head;
	A->head = first->next;
	A->head->prev = NULL;
	last = A->head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rb(t_stack *B)
{
	t_list	*first;
	t_list	*last;

	if (!B->head || !B->head->next)
		return ;
	first = B->head;
	B->head = first->next;
	B->head->prev = NULL;
	last = B->head;
	while (last->next)
		last = last->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rr(t_stack *A, t_stack *B)
{
	ra(A);
	rb(B);
}
