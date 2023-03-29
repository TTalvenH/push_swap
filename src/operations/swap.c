#include "push_swap.h"
#include "libft.h"

void	swap(int *stack, int *top)
{
	int	temp;

	if (*top > 0)
	{
		temp = stack[*top];
		stack[*top] = stack[*top - 1];
		stack[*top - 1] = temp;
	}		
}

void	sa(t_stacks *stack)
{
	swap(stack->a, &stack->ta);
	ft_printf("sa\n");
}

void	sb(t_stacks *stack)
{
	swap(stack->b, &stack->tb);
	ft_printf("sb\n");
}

void	ss(t_stacks *stack)
{
	swap(stack->a, &stack->ta);
	swap(stack->b, &stack->tb);
	ft_printf("ss\n");
}