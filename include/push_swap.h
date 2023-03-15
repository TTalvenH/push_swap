#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	int			*a;
	int			top_a;
	int			*b;
	int			top_b;
}t_stacks;

int		parse_int(char *str);
void	check_duplicates(int *arr, int size);
void	print_arr(int *arr, int size);
void	sa(t_stacks *stack);
void	sb(t_stacks *stack);
void	ss(t_stacks *stack);
void	pa(t_stacks *stack);
void	pb(t_stacks *stack);
void	ra(t_stacks *stack);
void	rb(t_stacks *b);
void	rr(t_stacks *stack);
void	rra(t_stacks *stack);
void	rrb(t_stacks *stack);
void	rrr(t_stacks *stack);
int		median(int *median, t_stacks *stack);
void	sort(t_stacks *stack);
int		is_sorted (t_stacks *stack);


#endif