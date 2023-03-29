/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:31:19 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/03/29 13:31:21 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <math.h>

void	sort_top_3(int *arr, int top, t_stacks *stack, int which_stack)
{
	stack->i = 3;
	if (!which_stack)
	{
		while (stack->i != 3 || is_sorted(arr + top - 2, 3, ASCENDING))
		{
			if (arr[top] > arr[top - 1])
				sa(stack);
			else if (stack->i == 3 && stack->i--)
				ra(stack);
			else if (stack->i++)
				rra(stack);
		}
	}
	else if (which_stack)
	{
		while (stack->i > 0)
		{
			if (stack->i > 1 && stack->b[stack->tb] < stack->b[stack->tb - 1])
				sb(stack);
			if (stack->i == 1 && stack->a[stack->ta] > stack->a[stack->ta - 1])
				sa(stack);
			else if (stack->i-- > 0)
				pa(stack);
		}
	}
}

void	sort_3(t_stacks *stack)
{
	while (is_sorted(stack->a, stack->ta + 1, ASCENDING))
	{
		if (stack->a[2] > stack->a[1] && stack->a[2] < stack->a[0])
			sa(stack);
		else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0])
			ra(stack);
		else
			rra(stack);
	}
}

void	sort_small(t_stacks *stack, int len, int which_stack)
{
	if (!which_stack)
	{
		if (len == 2 && stack->a[stack->ta] > stack->a[stack->ta - 1])
			sa(stack);
		else if (stack->ta == 2)
			sort_3(stack);
		else if (len == 3)
			sort_top_3(stack->a, stack->ta, stack, A_STACK);
	}
	else if (which_stack)
	{
		if (len == 2 && stack->b[stack->tb] < stack->b[stack->tb - 1])
			sb(stack);
		if (len < 3)
			while (len--)
				pa(stack);
		else if (len == 3)
			sort_top_3(stack->b, stack->tb, stack, B_STACK);
	}
}

void	quick_sort_a(int *arr, int len, t_stacks *stack)
{
	int	half;
	int	half_parity;
	int	pivot;
	int	under;

	under = 0;
	half = len / 2;
	half_parity = len / 2 + (len & 1);
	if (median(&pivot, stack->a + (stack->ta - len + 1), len))
		error(stack);
	if (len <= 3)
		return (sort_small(stack, len, A_STACK));
	while (len != half_parity)
	{
		if (arr[stack->ta] < pivot && len--)
			pb(stack);
		else if (++under)
			ra(stack);
	}
	while (half_parity != stack->ta + 1 && under--)
		rra(stack);
	quick_sort_a(stack->a, half_parity, stack);
	quick_sort_b(stack->b, half, stack);
}

void	quick_sort_b(int *arr, int len, t_stacks *stack)
{
	int	half;
	int	half_parity;
	int	pivot;
	int	under;

	under = 0;
	half = len / 2;
	half_parity = len / 2 + (len & 1);
	if (median(&pivot, stack->b + (stack->tb - len + 1), len))
		error(stack);
	if (len <= 3)
		return (sort_small(stack, len, B_STACK));
	while (len != half)
	{
		if (arr[stack->tb] >= pivot && len--)
			pa(stack);
		else if (++under)
			rb(stack);
	}
	while (half != stack->tb + 1 && under--)
		rrb(stack);
	quick_sort_a(stack->a, half_parity, stack);
	quick_sort_b(stack->b, half, stack);
}
