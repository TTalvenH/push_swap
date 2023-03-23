#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <math.h>


void    push_sort_top_3(int order, t_stacks *stack)
{
    int i;

    i = 3;
    if (order)
    {
        if (stack->top_a == 2)
            sort_3 (stack->a, stack->top_a, ASCENDING, stack);
        while (i > 0)
        {
                if (i > 1 && stack->a[stack->top_a] > stack->a[stack->top_a - 1])
                    sa(stack);
                if (i == 1 && stack->b[stack->top_b] < stack->b[stack->top_b - 1])
                    sb(stack);
                else if (i == 1 && i--)
                {
                    pa(stack);
                    pa(stack);
                }
                else if (i-- > 0)
                    pb(stack);
        }
    }
    else if (!order)
    {
        while (i > 0)
        {
            if (i > 1 && stack->b[stack->top_b] < stack->b[stack->top_b - 1])
                sb(stack);
            if (i == 1 && stack->a[stack->top_a] > stack->a[stack->top_a - 1])
                sa(stack);
            else if (i-- > 0)
                pa(stack);
        }
    }
}

void    sort_3(int *arr, int len, int order, t_stacks *stack)
{
    if (order)
    {
        while(is_sorted(arr, len, order))
        {
            if (arr[2] > arr[1] && arr[2] < arr[0])
                sa(stack);
            else if (arr[2] > arr[1] && arr[2] > arr[0])
                ra(stack);
            else
                rra(stack);
        }
    }
    else if (!order)
    {
        while(is_sorted(arr, len, order))
        {
            if (arr[2] < arr[1] && arr[2] > arr[0])
                sb(stack);
            else if (arr[2] < arr[1] && arr[2] < arr[0])
                rb(stack);
            else
                rrb(stack);
        }
    }
}

void    partition(t_stacks *stack, int len)
{
    int pivot;
    int i;

    if (stack->top_a <= 2)
    {
        if (stack->top_a == 2 && is_sorted(stack->a, stack->top_a + 1, ASCENDING))
            sort_3(stack->a, stack->top_a + 1, ASCENDING, stack);
        if (stack->top_a == 1 && is_sorted(stack->a, stack->top_a + 1, ASCENDING))
            sa(stack);
        return ;
    }
    i = stack->top_a;
    median(&pivot, stack->a, stack->top_a + 1);
    while (i-- > 0)
    {
        if (stack->a[stack->top_a] < pivot)
            pb(stack);
        else
            ra(stack);
    }
    partition(stack, stack->top_a + 1);
    quick_sort_b(stack->b, len - stack->top_a - 1, stack);
}

void    quick_sort_a(int *arr, int len, t_stacks *stack)
{
    int half;
    int half_parity;
    int pivot;
    int under;

    under = 0;
    half = len / 2;
    half_parity = len / 2 + (len & 1);
    median(&pivot, stack->a, len);
    if (len <= 3)
        return (push_sort_top_3(ASCENDING, stack));
    while (len != half_parity)
        if (arr[stack->top_a] < pivot && len--)
            pb(stack);
        else if (++under)
            ra(stack);
    while (half_parity != stack->top_a + 1 && under--)
        rra(stack);
    quick_sort_a(stack->a, half_parity, stack);
    quick_sort_b(stack->b, half, stack);
}

void    quick_sort_b(int *arr, int len, t_stacks *stack)
{
    int half;
    int half_parity;
    int pivot;
    int under;

    under = 0;
    half = len / 2;
    half_parity = len / 2 + (len & 1);
    median(&pivot, stack->b, len);
    if (len <= 3)
    {
        if (len == 1)
            pa(stack);
        else if (len == 2)
        {
            if (stack->b[stack->top_b] < stack->b[stack->top_b - 1])
                sb(stack);
            pa(stack);
            pa(stack);
        }
        else if (len == 3)
            push_sort_top_3(DESCENDING, stack);
        return ;
    }
    while (len != half)
    {
        ft_printf("len: %d, half: %d, pivot : %d\n", len, half, pivot);
        if (arr[stack->top_b] <= pivot && len--)
            pa(stack);
        else if (++under)
            rb(stack);
    }
    while (half != stack->top_b + 1 && under--)
        rrb(stack);
    quick_sort_a(stack->a, half_parity, stack);
    quick_sort_b(stack->b, half, stack);
}

void	sort(t_stacks *stack)
{
    // partition(stack, stack->top_a + 1);
    
    // sort_3(stack->a, stack->top_a, DESCENDING, stack);
    quick_sort_a(stack->a, stack->top_a + 1, stack);
    // quick_sort_b(stack->b, stack->top_b + 1, stack);
}   