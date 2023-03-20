#include "libft.h"
#include "push_swap.h"
#include <stdio.h>
#include <math.h>

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

void    quick_sort_a(int *arr, int len, t_stacks *stack)
{
    int pivot;
    int i;

    if (len <= 3)
    {  
        // if (len == 3 && is_sorted(arr, len, ASCENDING))
        //     sort_3(arr + stack->top_a - len + 1, len, ASCENDING, stack);
        if (len == 2 && is_sorted(arr, len, ASCENDING))
            sa(stack);
        return ;
    }
    i = len;
    median(&pivot, arr + (stack->top_a - len + 1), len);
    printf("A: %d and pivot:%d\n", len, pivot);
    len = 0;
    while (i > 0)
    {
        if (arr[stack->top_a] < pivot)
        {
            pb(stack);
            len ++;
        }
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
    {  
        // if (len == 3 && is_sorted(arr, len, DESCENDING))
        //     sort_3(arr + stack->top_b - len + 1, len, DESCENDING, stack);
        if (len == 2 && is_sorted(arr, len, DESCENDING))
            sb(stack);
        while (len > 0)
        {
            pa(stack);
            len --;
        }
        return ;
    }
    i = len;
    median(&pivot, arr + (stack->top_b - len + 1), len);
    printf("B: %d and pivot: %d\n", len, pivot);
    while (i > 0)
    {
        if (arr[stack->top_b] > pivot)
        {
            pa(stack);
            len --;
        }
        else 
            rb(stack);
        i--;
    }
    i = len;
    while (i > 0)
    {
        rrb(stack);
        i--;
    }
    quick_sort_b(arr, len, stack);
}

void	sort(t_stacks *stack)
{
    // sort_3(stack->a, stack->top_a, DESCENDING, stack);
    quick_sort_a(stack->a, stack->top_a + 1, stack);
    // quick_sort_b(stack->b, stack->top_b + 1, stack);
}   