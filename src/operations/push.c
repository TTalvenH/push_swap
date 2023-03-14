#include "push_swap.h"
#include "libft.h"

void	push(int *stack1, int *top1, int *stack2, int *top2)
{
	if (*top2 >= 0)
		stack1[(*top1)++ + 1] = stack2[(*top2)--];
}

void	pa(t_stacks *stack)
{
	push(stack->a, &stack->top_a, stack->b, &stack->top_b);
	ft_printf("pa\n");
}

void	pb(t_stacks *stack)
{
	push(stack->b, &stack->top_b, stack->a, &stack->top_a);
	ft_printf("pb\n");
}
