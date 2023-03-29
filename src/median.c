/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttalvenh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 13:30:55 by ttalvenh          #+#    #+#             */
/*   Updated: 2023/03/29 13:30:57 by ttalvenh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include "libft.h"

static int	partition(int *arr, int len)
{
	int	*temp;
	int	lower;
	int	upper;
	int	i;

	i = -1;
	lower = 0;
	upper = len - 1;
	temp = malloc (sizeof(int) * len + 1);
	if (!temp)
		return (-1);
	while (++i < len - 1)
	{
		if (arr[i] > arr[len - 1])
			temp[upper--] = arr[i];
		else
			temp[lower++] = arr[i];
	}
	temp[lower] = arr[len - 1];
	i = -1;
	while (++i < len)
		arr[i] = temp[i];
	free(temp);
	return (lower);
}

static int	quick_sort(int *arr, int len)
{
	int	part_index;

	if (len < 2)
		return (0);
	part_index = partition(arr, len);
	if (part_index < 0)
		return (-1);
	if (part_index)
		quick_sort(arr, part_index);
	if (part_index != len - 1)
		quick_sort(arr + part_index + 1, len - part_index - 1);
	return (0);
}

int	median(int *median, int *stack, int len)
{
	int	*temp;
	int	i;

	i = -1;
	temp = malloc(sizeof(int) * len);
	if (!temp)
		return (1);
	while (++i < len)
		temp[i] = stack[i];
	if (quick_sort(temp, len) < 0)
	{
		free(temp);
		return (1);
	}
	*median = temp[len / 2];
	free(temp);
	return (0);
}
