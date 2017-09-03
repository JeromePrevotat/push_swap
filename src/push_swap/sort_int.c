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

#include "../../inc/push_swap.h"

/*int		split(int *tab, int start, int end, int pivot)
{
	int	i;
	int j;

	if (pivot != end)
		swap_int(&tab[pivot], &tab[end]);
	j = start;
	i = start;
	while (i < end)
	{
		if (tab[i] < tab[end])
		{
			if (i != j)
				swap_int(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	if (end != j)
		swap_int(&tab[end], &tab[j]);
	return (j);
}

int		quicksort(int *tab, int start, int end)
{
	int pivot;

	pivot = start;
	if (start < end)
	{
		pivot = split(tab, start, end, pivot);
		quicksort(tab, start, pivot - 1);
		quicksort(tab, pivot + 1, end);
		return (1);
	}
	return (0);
}*/

int		split(t_pile *pile_a, int start, int end, int pivot)
{
	int	i;
	int j;

	if (pivot != end)
		swap_int(&pile_a->pile[pivot], &pile_a->pile[end]);
	j = start;
	i = start;
	while (i < end)
	{
		if (pile_a->pile[i] < pile_a->pile[end])
		{
			if (i != j)
				swap_int(&pile_a->pile[i], &pile_a->pile[j]);
			j++;
		}
		i++;
	}
	if (end != j)
		swap_int(&pile_a->pile[end], &pile_a->pile[j]);
	return (j);
}

int		quicksort(t_pile *pile_a, int start, int end, t_pile *pile_b)
{
	int pivot;

	pivot = start;
	if (start < end)
	{
		pivot = split(pile_a, start, end, pivot);
		quicksort(pile_a, start, pivot - 1, pile_b);
		quicksort(pile_a, pivot + 1, end, pile_b);
		return (1);
	}
	return (0);
}
