/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:46 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 11:17:58 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				*content;
}	t_list;

typedef struct s_stack {
	t_list	*head;
	int		size;
}t_stack;

t_list	*creat_node(int a);
int		ft_atoi(char *str);
int		distance_to_value(t_stack *stack, int index);
int		check_duplicates(t_stack *stack);
int		stack_size(t_stack *stack);
char	**ft_split(char const *s, char c);
char	**pars_list(char *str);
char	**pars_list_2(int ac, char **av, t_list *stack);
void	sort_3(t_stack *A);
void	sort_5(t_stack *A, t_stack *B);
void	sort(t_stack *A, t_stack *B);
void	stack_clear(t_stack *lst);
void	add_node_back(t_stack *stack, t_list *node);
void	print_stack(t_stack *stack);
//
void	pa(t_stack *A, t_stack *B);
void	pb(t_stack *A, t_stack *B);
void	rra(t_stack *A);
void	rrb(t_stack *B);
void	rrr(t_stack *A, t_stack *B);
void	sa(t_stack *A);
void	sb(t_stack *B);
void	ss(t_stack *A, t_stack*B);
void	ra(t_stack *A);
void	rb(t_stack *B);
void	rr(t_stack *A, t_stack *B);
#endif
