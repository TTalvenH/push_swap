/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:30:29 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/03/29 13:30:31 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	reverse_rotate(int *stack, int *top)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack[0];
	while (i < *top)
	{
		stack[0 + i] = stack[0 + 1 + i];
		i++;
	}
	stack[*top] = temp;
}

void	rra(t_stacks *stack)
{
	reverse_rotate(stack->a, &stack->ta);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stack)
{
	reverse_rotate(stack->b, &stack->tb);
	ft_printf("rrb\n");
}

void	rrr(t_stacks *stack)
{
	reverse_rotate(stack->a, &stack->ta);
	reverse_rotate(stack->b, &stack->tb);
	ft_printf("rrr\n");
}
