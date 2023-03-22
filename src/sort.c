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
        while (i > 0)
        {
            if (i > 1 && stack->a[stack->top_a] < stack->a[stack->top_a - 1])
                sa(stack);
            if (i == 1 && stack->b[stack->top_b] > stack->b[stack->top_b - 1])
                sb(stack);
            else if (i-- > 0)
                pb(stack);
        }   
        pa(stack);
        pa(stack);
        pa(stack);
    }
    else if (!order)
    {
        while (i > 0)
        {
            if (i > 1 && stack->b[stack->top_b] < stack->b[stack->top_b - 1])
            {
                
                ft_printf("test1\n");
                sb(stack);
            }
            if (i == 1 && stack->a[stack->top_a] > stack->a[stack->top_a - 1])
                sa(stack);
            else if (i-- > 0)
            {
                ft_printf("test2\n");
                pa(stack);
            }
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
    int pivot;
    int i;
    int upper;
    int lower;

    i = len;
    upper = 0;
    lower = 0;
    if (len <= 3)
    {
        if (len == 3)
        {
            push_sort_top_3(ASCENDING, stack);
            return ;
        }
        if (len == 2 && is_sorted(stack->a, stack->top_a + 1, ASCENDING))
            sa(stack);
        return ;
    }
    median(&pivot, arr + (stack->top_a - len), len);
    while(i-- > 0)
    {
        if (arr[stack->top_a] < pivot)
            lower++;
        if (arr[stack->top_a] < pivot)
            pb(stack);
        else
        {
            ra(stack);
            upper++;
        }
    }
    i = upper;
    while (i-- > 0)
        rra(stack);
    quick_sort_b(stack->b, lower, stack);
    quick_sort_a(stack->a, upper, stack);
}

void    quick_sort_b(int *arr, int len, t_stacks *stack)
{
    int pivot;
    int i;
    int upper;
    int lower;

    i = len;
    upper = 0;
    lower = 0;
    if (len <= 3)
    {
        if (len == 3)
        {
            push_sort_top_3(DESCENDING, stack);
            return ;
        }
        if (len == 2 && is_sorted(stack->b, stack->top_b + 1, DESCENDING))
            sb(stack);
        while (len-- > 0)
            pa(stack);
        return ;
    }
    median(&pivot, arr + (stack->top_b - len), len);
    while(i-- > 0)
    {
        if (arr[stack->top_b] > pivot)
            upper++;
        if (arr[stack->top_b] > pivot)
            pa(stack);
        else
        {
            rb(stack);
            lower++;
        }
    }
    i = lower;
    while (i-- > 0)
        rrb(stack);
    quick_sort_a(stack->a, upper, stack);
    quick_sort_b(stack->b, lower, stack);
}

void	sort(t_stacks *stack)
{
    partition(stack, stack->top_a + 1);
    // sort_3(stack->a, stack->top_a, DESCENDING, stack);
    // quick_sort_a(stack->a, stack->top_a + 1, stack);
    // quick_sort_b(stack->b, stack->top_b + 1, stack);
}   