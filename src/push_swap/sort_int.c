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

/*int		split(t_p *piles, int start, int end, int pivot)
{
	int	i;
	int j;

	if (pivot != end)
		swap_int(&piles->p_a->pile[pivot], &piles->p_a->pile[end]);
	j = start;
	i = start;
	while (i < end)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[end])
		{
			if (i != j)
				swap_int(&piles->p_a->pile[i], &piles->p_a->pile[j]);
			j++;
		}
		i++;
	}
	if (end != j)
		swap_int(&piles->p_a->pile[end], &piles->p_a->pile[j]);
	return (j);
}*/

int		split(t_p *piles, int start, int end, int pivot)
{
	//int		tmp;
	//size_t	i;

	if (start == 0 && end > 0)
		return (sort_left(piles, start, end, pivot));
	else if (start > 0 && end > 0)
		return (sort_rigth(piles, start, end, pivot));
	return (1);
}

int		quicksort(t_p *piles, int start, int end)
{
	int pivot;
	static int nb_call = 1;

	if (nb_call > 200)
		exit(0);
	pivot = start;
	//printf("NB_CALL : %d // START : %d // END : %d // PIVOT : %d\n", nb_call, start, end, piles->p_a->pile[pivot]);
	//ft_putendl("Pile A :");
	//print_tab(piles->p_a);
	nb_call++;
	if (start < end)
	{
		pivot = split(piles, start, end, pivot);
		quicksort(piles, start, pivot - 1);
		quicksort(piles, pivot + 1, end);
		return (1);
	}
	return (0);
}

int		sort_left(t_p *piles, int start, int end, int pivot)
{
	int		tmp;
	int		i;
	int		next_pivot;


	//printf(BLUE"SORT LEFT\n"RESET);
	i = start;
	tmp = piles->p_a->pile[pivot];
	if (piles->p_a->pile[pivot] == piles->max)
		reset(piles);
	else
	{
		if (start == 0 && end == 1)
		{
			if (piles->p_a->pile[0] > piles->p_a->pile[1])
				swap_a(piles->p_a);
			return (0);
		}
		push_b(piles->p_a, piles->p_b);
		while (i < end)
		{
			if (piles->p_a->pile[0] < tmp)
				push_b(piles->p_a, piles->p_b);
			else if (i < end - 1)
				rotate_a(piles->p_a);
			i++;
		}
		r_rotate_b(piles->p_b);
		reset(piles);
		while (piles->p_b->size != 0)
			push_a(piles->p_a, piles->p_b);
		i = 0;
		while (piles->p_a->pile[i] != tmp)
			i++;
	}
	next_pivot = 0;
	while (piles->p_a->pile[next_pivot] != tmp)
		next_pivot++;
	//printf(BLUE"SORT LEFT RETURN VALUE : %d\n"RESET, next_pivot);
	return (next_pivot);
}

int		sort_rigth(t_p *piles, int start, int end, int pivot)
{

	int		tmp;
	int		i;
	int		next_pivot;

	//SPLIT SUP
	//printf(GREEN"SORT RIGTH\n"RESET);
	i = 0;
	tmp = piles->p_a->pile[pivot];
	if (piles->p_a->pile[pivot] == piles->max)
		reset(piles);
	else
	{
		while (i != start)
		{
			rotate_a(piles->p_a);
			i++;
		}
		if (start == 1 && end == 2)
		{
			if (piles->p_a->pile[0] > piles->p_a->pile[1])
				swap_a(piles->p_a);
			return (0);
		}
		push_b(piles->p_a, piles->p_b);
		while (i < end)
		{
			if (piles->p_a->pile[0] > tmp)
				push_b(piles->p_a, piles->p_b);
			else
				rotate_a(piles->p_a);
			i++;
		}
		r_rotate_b(piles->p_b);
		while (piles->p_b->size != 0)
			push_a(piles->p_a, piles->p_b);
		reset(piles);
	}
	next_pivot = 0;
	while (piles->p_a->pile[next_pivot] != tmp)
		next_pivot++;
	//printf(GREEN"SORT RIGTH RETURN VALUE : %d\n"RESET, next_pivot);
	return (next_pivot);
}
