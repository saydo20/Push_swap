/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:57 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:20:58 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void SA(t_list **A)
{
    t_list *first;
    t_list *second;

    if (!A || !(*A) || !(*A)->next)
        return;
    first = *A;
    second = (*A)->next;
    first->next = second->next;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    *A = second;
    printf("sa\n");
}

void SB(t_list **B)
{
    t_list *first;
    t_list *second;

    if (!B || !(*B) || !(*B)->next)
        return;
    first = *B;
    second = (*B)->next;
    first->next = second->next;
    second->next = first;
    second->prev = NULL;
    first->prev = second;
    *B = second;
    printf("sb\n");
}

void    SS(t_list **A, t_list **B)
{
    SA(A);
    SB(B);
    printf("ss\n");
}
