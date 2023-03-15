#include "push_swap.h"
#include <stdlib.h>

int	partition(int *arr, int len)
{
	int	*temp;
	int lower;
	int upper;
	int i;

	i = -1;
	lower = 0;
	upper = len - 1;
	temp = malloc (sizeof(int) * len);
	while (++i < len - 1)
		if (arr[i] > arr[len - 1])
			temp[upper--] = arr[i];
		else
			temp[lower++] = arr[i];
	temp[lower] = arr[len - 1];
	i = -1;
	while (++i < len)
		arr[i] = temp[i];
	return (lower);
}


void	quick_sort(int *arr, int len)
{
	int	part_index;
	
	if (len < 2)
		return ;
	part_index = partition(arr, len);
	if (part_index)
		quick_sort(arr, part_index);
	if (part_index != len - 1)
		quick_sort(arr + part_index + 1, len - part_index - 1);
}

int	median(int *median, t_stacks *stack)
{
	int	*temp;
	int i;
	int len;

	len = stack->top_a + 1;
	i = -1;
	temp = malloc(sizeof(int) * len);
	if (!temp)
		return (1);
	while (++i < len)
		temp[i] = stack->a[i];
	quick_sort(temp, len);
	*median = temp[len / 2];
	free(temp);
	return (0);
}