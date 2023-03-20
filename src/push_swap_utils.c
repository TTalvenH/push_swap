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

int	is_sorted (int *arr, int len, int order)
{
	int	i;

	i = 0;
	if (order)
	{
		while (i < len - 1)
		{
			if (arr[i] < arr[i + 1])
				return (1);
			i++;
		}
	}
	else if (!order)
	{
		while (i < len - 1)
		{
			if (arr[i] > arr[i + 1])
				return (1);
			i++;
		}
	}
	return (0);
}