#include "libft.h"
#include "push_swap.h"

static int	check_max_min(int i, int next_digit)
{
	if (i >= 0)
	{
		if (i > INT_MAX / 10
			|| (i == INT_MAX / 10 && next_digit > INT_MAX % 10))
			return (1);
	}
	else
	{
		if (i < (INT_MIN / 10)
			|| (i == (INT_MIN / 10) && - next_digit < (INT_MIN % -10)))
			return (1);
	}
	return (0);
}

int	parse_int(char *str)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	while (*str != '\0')
	{
		if (!ft_isdigit(*str) || check_max_min(i, *str - '0'))
		{
			ft_printf_fd(2, "Error\n");
			exit (-1);
		}
		i = i * 10 + (*str - '0') * sign;
		str++;
	}
	return (i);
}
