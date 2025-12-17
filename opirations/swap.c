/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:57 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 09:53:36 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sa(t_stack *A)
{
	t_list	*first;
	t_list	*second;

	if (!A || !(A->head) || !A->head->next)
		return ;
	first = A->head;
	second = (A)->head->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	A->head = second;
	write(1, "sa\n", 3);
}

void	sb(t_stack *B)
{
	t_list	*first;
	t_list	*second;

	if (!B || !(B->head) || !B->head->next)
		return ;
	first = B->head;
	second = (B)->head->next;
	first->next = second->next;
	second->next = first;
	second->prev = NULL;
	first->prev = second;
	B->head = second;
	write(1, "pb\n", 3);
}

void	ss(t_stack *A, t_stack*B)
{
	sa(A);
	sb(B);
	write(1, "ss\n", 3);
}
