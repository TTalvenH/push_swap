#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	error(t_stacks *stack)
{
	if (stack->a)
		free (stack->a);
	if (stack->b)
		free (stack->b);
	ft_printf_fd(2, "Error\n");
	exit(1);
}

void	init_stacks(int size, char **array, t_stacks *stack)
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	stack->a = malloc (sizeof(int) * size);
	stack->b = malloc (sizeof(int) * size);
	if (!stack->a || !stack->b)
		error(stack);
	stack->ta = 0;
	stack->tb = -1;
	while (i < size)
	{
		if (array[size] == NULL)
			offset = 1;
		stack->a[stack->ta++] = parse_int(array[size - i++ - offset], stack);
	}
	stack->ta--;
	check_duplicates(stack->a, size);
}

int	main(int argc, char **argv)
{
	t_stacks	stack;
	int			size;
	char		**array;

	size = 0;
	if (argc > 1)
	{
		if (argc == 2)
		{
			array = ft_split(argv[1], ' ');
			if (!array)
				error(&stack);
			while (array[size] != NULL)
				size++;
			init_stacks(size, array, &stack);
			ft_free_array(array);
		}
		else
			init_stacks(argc - 1, argv, &stack);
		if (is_sorted(stack.a, stack.ta + 1, ASCENDING))
			quick_sort_a(stack.a, stack.ta + 1, &stack);
		free(stack.a);
		free(stack.b);
	}
}
