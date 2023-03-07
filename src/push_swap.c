#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	init_stacks(int size, char **array, t_stack *a, t_stack *b)
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	a->arr = malloc (sizeof(int) * size);
	a->top = 0;
	b->arr = malloc (sizeof(int) * size);
	b->top = -1;
	while (i < size)
	{
		if (array[size] == NULL)
			offset = 1;
		a->arr[a->top++] = parse_int(array[size - i++ - offset]);
	}
	a->top--;
	check_duplicates(a->arr, size);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	int		size;
	char	**array;

	size = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			array = ft_split(argv[1], ' ');
			while (array[size] != NULL)
				size++;
			init_stacks(size, array, &a, &b);
		}
		else
			init_stacks(argc - 1, argv, &a, &b);
		quick_sort(&a, &b);
		ft_printf("a: "); print_arr(a.arr, a.top + 1);
		ft_printf("b: "); print_arr(b.arr, b.top + 1);
		free(a.arr);
		free(b.arr);
	}
}
