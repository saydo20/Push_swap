/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:10:32 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/19 16:10:33 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	exec_instruction(char *line, t_stack *a, t_stack *b)
{
	if (ft_strcmp(line, "pa\n") == 0)
    	pa(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
    	pb(a, b);
	else if (ft_strcmp(line, "rra\n") == 0)
    	rra(a);
	else if (ft_strcmp(line, "rrb\n") == 0)
    	rrb(b);
	else if (ft_strcmp(line, "rrr\n") == 0)
    	rrr(a, b);
	else if (ft_strcmp(line, "sa\n") == 0)
    	sa(a);
	else if (ft_strcmp(line, "sb\n") == 0)
    	sb(b);
	else if (ft_strcmp(line, "ss\n") == 0)
    	ss(a, b);
	else if (ft_strcmp(line, "ra\n") == 0)
    	ra(a);
	else if (ft_strcmp(line, "rb\n") == 0)
    	rb(b);
	else if (ft_strcmp(line, "rr\n") == 0)
    	rr(a, b);
	else
		return ;
}

int	is_valid_instruction(char *str)
{
	if (ft_strcmp(str, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (1);
	else
		return 0;
}

int		is_sorted(t_stack *a)
{
	t_list	*tmp;

	tmp = a->head;
	while(tmp->next)
	{
		if (!tmp->next)
			return (0);
		else if (*tmp->content < *tmp->next->content)
			tmp = tmp->next;
		else
			return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (ac < 2)
		return (0);
	fill_ptr(av, &a);
	check_duplicates(&a);
	char	*ptr;
	ptr = get_next_line(0);
	while(ptr)
	{
		if (!is_valid_instruction(ptr))
		{
			free(ptr);
        	full_exit(&a);
		}
		exec_instruction(ptr, &a, &b);
		free(ptr);
		ptr = get_next_line(0);
	}
	free(ptr);
	if (is_sorted(&a) && b.size == 0)
    	write(1, "OK\n", 3);
	else
    	write(1, "KO\n", 3);
	stack_clear(&a);
	stack_clear(&b);
    return 0;
}
