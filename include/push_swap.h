/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:31:54 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/03/29 13:31:56 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define B_STACK 1
# define A_STACK 0
# define ASCENDING 1
# define DESCENDING 0

typedef struct s_stacks
{
	int			*a;
	int			ta;
	int			*b;
	int			tb;
	int			i;
}t_stacks;

int		parse_int(char *str, t_stacks *stack);
void	check_duplicates(int *arr, int size);
void	print_arr(int *arr, int size);
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ss(t_stacks *stack);
void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
void	ra(t_stacks *stack);
void	rb(t_stacks *b);
void	rr(t_stacks *stack);
void	rra(t_stacks *stack);
void	rrb(t_stacks *stack);
void	rrr(t_stacks *stack);
void	error(t_stacks *stack);
int		median(int *median, int *stack, int len);
void	quick_sort_a(int *arr, int len, t_stacks *stack);
void	sort(t_stacks *stack);
void	sort_3(t_stacks *stack);
void	sort_top_3(int *arr, int top, t_stacks *stack, int which_stack);
void	push_sort_top_3(int order, t_stacks *stack);
int		is_sorted(int *arr, int len, int order);
void	quick_sort_b(int *arr, int len, t_stacks *stack);
#endif
