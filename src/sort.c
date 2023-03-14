#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <math.h>

int find_best_pivot(int* stack, int stack_size) 
{
    int best_pivot = INT_MAX;
    int smallest_difference = INT_MAX;

    for (int i = 0; i < stack_size; i++)
	{
        int pivot = stack[i];
        int less_than_pivot_size = 0;
        int greater_than_pivot_size = 0;

        for (int j = 0; j < stack_size; j++)
		{
            if (stack[j] < pivot)
                less_than_pivot_size++;
			else if (stack[j] > pivot)
                greater_than_pivot_size++;
        }

        int difference = abs(less_than_pivot_size - greater_than_pivot_size);

        if (difference < smallest_difference)
		{
            smallest_difference = difference;
            best_pivot = pivot;
        }
    }
	ft_printf("%d\n", best_pivot);
    return best_pivot;
}

void    sort_3(t_stacks *stack)
{
    while(is_sorted(stack))
    {
        if (stack->a[2] < stack->a[1])
            sa(stack);
        else
            ra(stack);
    }
}

void	sort(t_stacks *stack)
{
    if (stack->top_a == 2)
        sort_3(stack);
}   