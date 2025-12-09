/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:14 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:20:15 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void    RRA(t_list **A)
{
    t_list  *tmp;
    t_list  *last;
    t_list  *new_last;

    tmp = *A;
    last = *A;
    
    while(last->next)
        last = last->next;
    new_last = last->prev;
    new_last->next = NULL;
    *A = last;
    last->next = tmp;
    last->prev = NULL;
    printf("rra\n");
}

void    RRB(t_list **B)
{
    t_list  *tmp;
    t_list  *last;
    t_list  *new_last;

    tmp = *B;
    last = *B;
    
    while(last->next)
        last = last->next;
    new_last = last->prev;
    new_last->next = NULL;
    *B = last;
    last->next = tmp;
    last->prev = NULL;
    printf("rrb\n");
}

void    RRR(t_list **A, t_list **B)
{
    RRB(B);
    RRA(A);
    printf("rrr\n");
}