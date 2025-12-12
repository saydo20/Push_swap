/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:31 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 10:44:21 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	i;
	t_list	*tmp ;
	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*creat_node(int a)
{
	t_list	*ptr;
	int		*num;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	num = malloc(sizeof(int));
	if (!num)
	{
		free(ptr);
		return (NULL);
	}
	*num = a;
	ptr->content = num;
	ptr->next = NULL;
	ptr->prev = NULL;
	return (ptr);
}

void	print_stack(t_stack *stack)
{
	t_list	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		printf("%d => ", *tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}

void	add_node_back(t_stack *stack, t_list *node)
{
	t_list	*tmp;

	if (!stack->head)
	{
		stack->head = node;
	}
	else
	{
		tmp = stack->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
	stack->size++;
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;
	int		i;
	int		j;
	char	**ptr;

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (ac < 2)
		return (0);
	j = 1;
	while (av[j])
	{
		ptr = pars_list(av[j++]);
		i = 0;
		while (ptr[i])
		{
			add_node_back(&a, creat_node(ft_atoi(ptr[i++])));
			free(ptr[i++]);
		}
		free(ptr);
	}
	check_duplicates(&a);
	sort_5(&a, &b);
    print_stack(&a);
}
