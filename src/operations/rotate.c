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
	rotate(stack->a, &stack->top_a);
	ft_printf("ra\n");
}

void	rb(t_stacks *stack)
{
	rotate(stack->b, &stack->top_b);
	ft_printf("rb\n");
}

void	rr(t_stacks *stack)
{
	rotate(stack->a, &stack->top_a);
	rotate(stack->b, &stack->top_b);
	ft_printf("rr\n");
}
