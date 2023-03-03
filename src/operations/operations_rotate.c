#include "../push_swap.h"
#include "../../libft/libft.h"

void	rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->arr[stack->top];
	while (i < stack->top)
	{
		stack->arr[stack->top - i] = stack->arr[stack->top - 1 - i];
		i++;
	}
	stack->arr[0] = temp;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
