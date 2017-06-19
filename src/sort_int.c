/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_int(int *a, int *b)
{
	int	tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

int		split(int *tab, int start, int end, int pivot)
{
	int	i;
	int j;

	swap_int(&tab[pivot], &tab[end]);
	j = start;
	i = 0;
	while (i < end && j < end)
	{
		if (tab[i] < tab[end])
		{
			swap_int(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	swap_int(&tab[end], &tab[j]);
	return (j);
}

int		quicksort(int *tab, int start, int end)
{
	int	pivot;

	pivot = 0;
	if (start < end)
	{
		pivot = split(tab, start, end, pivot);
		ft_putnbr(pivot);
		ft_putchar('\n');
		if (pivot - 1 <= end)
			quicksort(tab, start, pivot - 1);
		if (pivot + 1 >= start)
			quicksort(tab, pivot + 1, end);
		return (1);
	}
	return (0);
}
