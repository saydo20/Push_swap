/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:33 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:20:34 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void    RA(t_list **A)
{
    t_list *tmp;
    t_list *last;

    if (!A || !(*A))
        return;
    tmp = *A;
    last = *A;
    *A = (*A)->next;
    (*A)->prev = NULL;
    while(last->next)
        last = last->next;
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
    printf("ra\n");
}

void    RB(t_list **B)
{
    t_list *tmp;
    t_list *last;

    if (!B || !(*B))
        return;
    tmp = *B;
    last = *B;
    *B = (*B)->next;
    (*B)->prev = NULL;
    while(last->next)
        last = last->next;
    last->next = tmp;
    tmp->prev = last;
    tmp->next = NULL;
    printf("rb\n");
}

void    RR(t_list **A, t_list **B)
{
    RA(A);
    RB(B);
    printf("rr\n");
}