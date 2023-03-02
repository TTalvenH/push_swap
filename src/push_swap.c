#include "../libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

void	init_stacks(int size, char **argv, t_stack *a, t_stack *b)
{
	int		i;

	a->arr = malloc (sizeof(int) * size);
	a->top = 0;
	b->arr = malloc (sizeof(int) * size);
	b->top = 0;
	i = 0;
	while (i < size)
		a->arr[a->top++] = parse_int(argv[size - i++]);
	check_duplicates(a->arr, size);
}

int	main(int argc, char **argv)
{
	t_stack stack_a;
	t_stack stack_b;

	if (argc > 1)
	{
		init_stacks(argc - 1, argv, &stack_a, &stack_b);
		print_arr(stack_a.arr, stack_a.top);
		free(stack_a.arr);
	}
	else
		ft_printf("Like this: ./push_swap stack\n");
}