#include "../push_swap.h"
#include "../../libft/libft.h"

void	push(t_stack *a, t_stack *b)
{
	if (b->top >= 0)
		a->arr[a->top++ + 1] = b->arr[b->top--];
}

void	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	push(b, a);
	ft_printf("pa\n");
}
