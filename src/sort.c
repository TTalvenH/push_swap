#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <math.h>


void   sort_top_3(int *arr, int top, t_stacks *stack, int which_stack)
{
    int i;

    i = 3;
    if (!which_stack)
        while (i != 3 || is_sorted(arr + top - 2, 3, ASCENDING))
        {
            if (arr[top] > arr[top - 1])
                sa(stack);
            else if (i == 3 && i--)
                ra(stack);
            else if (i++)
                rra(stack);
        }
    else if (which_stack)
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

void    sort_small(t_stacks *stack, int len, int which_stack)
{
    if (!which_stack)
    {
        if (len == 2 && stack->a[stack->top_a] > stack->a[stack->top_a - 1])
            sa(stack);
        else if (len == 3)
            sort_top_3(stack->a, stack->top_a, stack, A_STACK);
    }
    else if (which_stack)
    {
        if (len == 2 && stack->b[stack->top_b] < stack->b[stack->top_b - 1])
            sb(stack);
        if (len < 3)
            while (len--)
                pa(stack);
        else if (len == 3)
            sort_top_3(stack->b, stack->top_b, stack, B_STACK);
    }
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
    median(&pivot, stack->a + (stack->top_a - len + 1), len);
    if (len <= 3)
        return (sort_small(stack, len, A_STACK));
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
    median(&pivot, stack->b + (stack->top_b - len + 1), len);
    if (len <= 3)
        return (sort_small(stack, len, B_STACK));
    while (len != half)
        if (arr[stack->top_b] >= pivot && len--)
            pa(stack);
        else if (++under)
            rb(stack);
    while (half != stack->top_b + 1 && under--)
        rrb(stack);
    quick_sort_a(stack->a, half_parity, stack);
    quick_sort_b(stack->b, half, stack);
}