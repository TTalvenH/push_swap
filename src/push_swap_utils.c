#include "libft.h"
#include "push_swap.h"

void	print_arr(int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
		ft_printf("%d ", arr[i++]);
	ft_printf("\n");

}

void	check_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				ft_printf_fd(2, "Error\n");
				exit(-1);
			}
			j++;
		}
		i++;
	}
}

int	is_sorted (t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->top)
	{
		if (a->arr[i] < a->arr[i + 1])
			return (1);
		i++;
	}
	return (0);
}