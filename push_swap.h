/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:46 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/19 11:23:16 by sjdia            ###   ########.fr       */
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
	int				rank;
}	t_list;

typedef struct s_stack {
	t_list	*head;
	int		size;
}t_stack;

t_list	*creat_node(int a);
int		ft_atoi(char *str, t_stack *stack);
int		stack_size(t_stack *stack);
int		find_max(t_stack *stack);
int		find_pos_max(t_stack *stack);
int		find_smallest_in_a(t_stack *A);
int		is_valid_int(char *str);
char	**ft_split(char const *s, char c);
char	**pars_list(char **ptr, t_stack *stack);
void	sort_3(t_stack *A);
void	sort_5(t_stack *A, t_stack *B);
void	stack_clear(t_stack *stack);
void	sort(t_stack *A, t_stack *B);
void	stack_clear(t_stack *lst);
void	add_node_back(t_stack *stack, t_list *node);
void	sort_large(t_stack *A, t_stack *B);
void	check_duplicates(t_stack *stack);
void	fill_ptr(char **av, t_stack *A);
void	full_exit(t_stack *stack);
void	*free_split(int index, char **s);
void	push_the_smallest_to_b(t_stack *A, t_stack *B, int pos);
//opirations
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
