/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:31 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:19:32 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_list *creat_node(void *a)
{
    t_list *ptr;
    ptr = malloc(sizeof(t_list));
    if (!ptr)
        return (NULL);
    ptr->content = a;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
}
void    print_list(t_list *head)
{
    while(head)
    {
        printf("%d=>", *head->content);
        head = head->next;
    }
    printf("\n");
}
void add_node_back(t_list **head, t_list *new)
{
    if (!*head)
    {
        *head = new;
        return;
    }
    t_list *tmp = *head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new;
    new->prev = tmp;
}

int main(int ac, char **av)
{
    t_list *A = NULL;
    t_list *B = NULL;
    int i;
    int j;
    char **ptr;
    
    j = 1;
    if (ac > 1)
    {
        while(av[j])
        {
            ptr = pars_list(av[j]);
            if (!ptr)
            {
                printf("error!\n");
                return 1;
            }
            i = 0;
            while(ptr[i])
            {
                int *num = malloc(sizeof(int));
                if (!num)
                {
                    printf("error!\n");
                    return 1;
                }
                *num = ft_atoi(ptr[i]);
                add_node_back(&A, creat_node(num));
                i++;
            }
            j++;
        }
        if(!(check_duplicates(A)))
        {
            printf("error!\n");
            return 1;
        }
    }
    print_list(A);
    return (0);
}
