/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:30:22 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/03/29 13:30:24 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	push(int *stack1, int *top1, int *stack2, int *top2)
{
	if (*top2 >= 0)
		stack1[(*top1)++ + 1] = stack2[(*top2)--];
}

void	pa(t_stacks *stack)
{
	push(stack->a, &stack->ta, stack->b, &stack->tb);
	ft_printf("pa\n");
}

void	pb(t_stacks *stack)
{
	push(stack->b, &stack->tb, stack->a, &stack->ta);
	ft_printf("pb\n");
}
