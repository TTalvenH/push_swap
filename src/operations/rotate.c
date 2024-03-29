/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:30:35 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/03/29 13:30:37 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate(int *stack, int *top)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[*top];
	while (i < *top)
	{
		stack[*top - i] = stack[*top - 1 - i];
		i++;
	}
	stack[0] = temp;
}

void	ra(t_stacks *stack)
{
	rotate(stack->a, &stack->ta);
	ft_printf("ra\n");
}

void	rb(t_stacks *stack)
{
	rotate(stack->b, &stack->tb);
	ft_printf("rb\n");
}

void	rr(t_stacks *stack)
{
	rotate(stack->a, &stack->ta);
	rotate(stack->b, &stack->tb);
	ft_printf("rr\n");
}
