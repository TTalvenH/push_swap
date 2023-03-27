#include "libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	init_stacks(int size, char **array, t_stacks *stack)
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	stack->a = malloc (sizeof(int) * size);
	stack->top_a = 0;
	stack->b = malloc (sizeof(int) * size);
	stack->top_b = -1;
	while (i < size)
	{
		if (array[size] == NULL)
			offset = 1;
		stack->a[stack->top_a++] = parse_int(array[size - i++ - offset]);
	}
	stack->top_a--;
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
			while (array[size] != NULL)
				size++;
			init_stacks(size, array, &stack);
		}
		else
			init_stacks(argc - 1, argv, &stack);
		// ft_printf("a: "); print_arr(stack.a, stack.top_a + 1);
		// ft_printf("b: "); print_arr(stack.b, stack.top_b + 1);
		// ft_printf("\n");

		sort(&stack);
		// push_sort_top_3(ASCENDING, &stack);
		// sort_top_3(stack.a, stack.top_a, &stack);

		// ft_printf("\n");
		// ft_printf("a: "); print_arr(stack.a, stack.top_a + 1);      
		// ft_printf("b: "); print_arr(stack.b, stack.top_b + 1);
		// if (!is_sorted (stack.a, stack.top_a + 1, ASCENDING))
		// 	ft_printf("IS sorted\n");
		// else
		// 	ft_printf("NOT sorted\n");
		free(stack.a);
		free(stack.b);
	}
}
