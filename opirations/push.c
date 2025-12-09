/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:01 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:20:02 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void    PA(t_list **A, t_list **B)
{
    t_list *tmp_b;

    if (!B || !(*B))
        return;
    tmp_b = *B;
    *B = (*B)->next;
    if (*B)
        (*B)->prev = NULL;
    tmp_b->next = *A;
    if (*A)
        (*A)->prev = tmp_b;
    tmp_b->prev = NULL;
    *A = tmp_b;

    printf("pa\n");
}

void    PB(t_list **A, t_list **B)
{
    t_list *tmp_a;

    if (!A || !(*A))
        return;
    tmp_a = *A;
    *A = (*A)->next;
    if (*A)
        (*A)->prev = NULL;
    tmp_a->next = *B;
    if (*B)
        (*B)->prev = tmp_a;
    tmp_a->prev = NULL;
    *B = tmp_a;

    printf("pb\n");
}