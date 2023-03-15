#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <math.h>

void    sort_3(t_stacks *stack)
{
    while(is_sorted(stack))
    {
        if (stack->a[2] > stack->a[1] && stack->a[2] < stack->a[0])
            sa(stack);
        else if (stack->a[2] > stack->a[1] && stack->a[2] > stack->a[0])
            ra(stack);
        else
            rra(stack);
    }
}

// void    ra_or_rra(int *stack, int *top, int i)
// {

// }

// void    quick_sort(int *stack, int *top, t_stacks *stack)
// {
//     int pivot;
//     int i;

//     i = *top;
//     pivot = find_best_pivot(stack, *top);
//     while (i > 0)
//     {
//         if (stack[i] < pivot)
//             move to b
//         i--;
//     }
    
// }

void	sort(t_stacks *stack)
{
    int pivot;

    median(&pivot, stack);
    ft_printf("pivot: %d\n", pivot);
}   