#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stack
{
	int			*arr;
	int			top;
}t_stack;

int		parse_int(char *str);
void	check_duplicates(int *arr, int size);
void	print_arr(int *arr, int size);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void	rotate(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rr(t_stack *a, t_stack *b);
void	reverse_rotate(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrr(t_stack *a, t_stack *b);
int		median(t_stack *a);
int		find_best_pivot(int* stack, int stack_size);
void	sort(t_stack *a, t_stack *b);
int		is_sorted (t_stack *a);


#endif