#include "push_swap.h"
#include "libft.h"

void	reverse_rotate(t_stack *stack)
{
	int	i;
	int	temp;

	i = 0;
	temp = stack->arr[0];
	while (i < stack->top)
	{
		stack->arr[0 + i] = stack->arr[0 + 1 + i];
		i++;
	}
	stack->arr[stack->top] = temp;
}

void	rra(t_stack *a)
{
	reverse_rotate(a);
	ft_printf("rra\n");
}

void	rrb(t_stack *b)
{
	reverse_rotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	reverse_rotate(a);
	reverse_rotate(b);
	ft_printf("rrr\n");
}
