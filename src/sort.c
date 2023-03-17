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

void    quick_sort_a(int *arr, int len, t_stacks *stack)
{
    int pivot;
    int i;

    // if (len == 2 && is_sorted(stack))
    //     sa(stack);
    // if (len == 3 && is_sorted(stack))
    //     sort_3(stack);
    if (len <= 3)
    {
        return ;
    }
    i = len;
    median(&pivot, arr, len);
    while (i > 0)
    {
        if (arr[stack->top_a] < pivot)
            pb(stack);
        else
            ra(stack);
        i--;
    }
    quick_sort_a(arr, stack->top_a + 1, stack);
    quick_sort_b(stack->b,  len, stack);
}

void    quick_sort_b(int *arr, int len, t_stacks *stack)
{
    int pivot;
    int i;

    if (len <= 3)
        return ;
    i = len;
    median(&pivot, arr + (stack->top_b - len), len);
    while (i > 0)
    {
        if (arr[stack->top_b] > pivot)
            pa(stack);
        else 
            rb(stack);
        i--;
    }
    quick_sort_b (arr, stack->top_b, stack);
}

void	sort(t_stacks *stack)
{
    quick_sort_a(stack->a, stack->top_a + 1, stack);
    // quick_sort_b(stack->b, stack->top_b + 1, stack);
}   