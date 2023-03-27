#include "push_swap.h"
#include "libft.h"

void	swap(int *stack, int *top)
{
	int temp;

	if (*top > 0)
	{
		temp = stack[*top];
		stack[*top] = stack[*top - 1];
		stack[*top - 1] = temp;
	}		
}

void	sa(t_stacks *stack)
{
	swap(stack->a, &stack->top_a);
	ft_printf("sa\n");
}

void	sb(t_stacks *stack)
{
	swap(stack->b, &stack->top_b);
	ft_printf("sb\n");
}

void	ss(t_stacks *stack)
{
	swap(stack->a, &stack->top_a);
	swap(stack->b, &stack->top_b);
	ft_printf("ss\n");
}