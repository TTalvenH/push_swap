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

// void	quick_sort(int  *a, int n,  t_stack *b)
// {
//     int pivot;
//     int i; 
//     int j; 

//     if (n <= 1)
//         return;
//     pivot = find_best_pivot(a, n);
//     i = -1; 
//     j = n;
//     while (i < j)
//     {
//         while (a[++i] < pivot && i < n);
//         while (a[--j] > pivot && j > 0);
//         if (i < j && a[i] > a[j])
//             sa(a);
//     }
// }

void quick_sort(int *a, int n) {
    if (n <= 1) {
        return;
    }

    // choose pivot element
    int pivot = find_median(a, n);

    // partition array around pivot
    int i = -1, j = n;
    while (i < j) {
        while (a[++i] < pivot && i < n);
        while (a[--j] > pivot && j > 0);
        if (i < j && a[i] > a[j])
            sa(a, n);
    }

    // recursively sort sub-arrays
    quick_sort(a, i);
    quick_sort(a + i, n - i);

    // concatenation of sub-arrays
    // push all elements less than pivot to stack B
    // push pivot and all elements greater than or equal to pivot to stack A
    int b[n], top_b = -1, top_a = n - 1;
    for (int i = 0; i < n; i++) {
        if (a[i] < pivot) {
            pb(a, &top_a, b, &top_b);
        } else {
            ra(a, n, i);
        }
    }
    while (top_b >= 0) {
        pa(a, &top_a, b, &top_b);
    }
}