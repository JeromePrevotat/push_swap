/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_p *piles)
{
	int	pivot;

	get_min(piles);
	if (small_pile(piles) == 1)
		return ;
	piles->index_to_sort = 1;
	while ((size_t)piles->index_to_sort != piles->p_a->size)
	{
		move_min(piles, piles->p_a->size - piles->index_to_sort);
		pivot = piles->p_a->pile[0];
		push_b(piles, 1);
		fill_b(piles, pivot);
		move_min(piles, piles->p_a->size - piles->index_to_sort);
		r_rotate_b(piles, 1);
		empty_b(piles);
		get_next_sort_index(piles);
	}
	move_min(piles, 0);
	printf("PILE A END :\n");
	print_tab(piles->p_a);
}

void get_next_sort_index(t_p *piles)
{
	int	i;

	i = 1;
	if (piles->p_a->pile[0] == piles->min || (size_t)piles->index_to_sort == piles->p_a->size)
		return ;
	while ((size_t)i < piles->p_a->size - piles->index_to_sort && piles->p_a->pile[i] != piles->min)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[0])
			return ;
		i++;
	}
	piles->index_to_sort++;
}

void	empty_b(t_p *piles)
{
	while (piles->p_b->size > 0)
	{
		check_swap(piles);
		push_a(piles, 1);
	}
	rotate_a(piles, 1);
	piles->index_to_sort++;
}

void	fill_b(t_p *piles, int pivot)
{
	while (exist_smallest(piles, pivot) == TRUE)
	{
		if (piles->p_a->pile[0] < pivot)
			push_b(piles, 1);
		else
			rotate_a(piles, 1);
	}
}

int		exist_smallest(t_p *piles, int pivot)
{
	int	i;

	i = 0;
	while (i < piles->min_index)
	{
		if (piles->p_a->pile[i] < pivot)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	move_min(t_p *piles, int index_to_place)
{
	int	i;

	i = 0;
	if (piles->min_index < index_to_place)
		move_min_down(piles, index_to_place);
	else
		move_min_up(piles, index_to_place);
	piles->min_index = index_to_place;
}

void	move_min_up(t_p *piles, int index_to_place)
{
	int	i;

	i = 0;
	if ((size_t)(piles->min_index - index_to_place) < piles->p_a->size / 2)
	{
		i = piles->min_index - index_to_place;
		while (i > 0)
		{
			rotate_a(piles, 1);
			i--;
		}
	}
	else
	{
		i = piles->p_a->size - (piles->min_index - index_to_place);
		while (i > 0)
		{
			r_rotate_a(piles, 1);
			i--;
		}
	}
}

void	move_min_down(t_p *piles, int index_to_place)
{
	int	i;

	i = 0;
	if ((size_t)(index_to_place - piles->min_index) > piles->p_a->size / 2)
	{
		i = piles->p_a->size - (index_to_place - piles->min_index);
		while (i > 0)
		{
			rotate_a(piles, 1);
			i--;
		}
	}
	else
	{
		i = index_to_place - piles->min_index;
		while (i > 0)
		{
			r_rotate_a(piles, 1);
			i--;
		}
	}
}

void	get_min(t_p *piles)
{
	size_t	i;

	i = 0;
	piles->min = piles->p_a->pile[0];
	piles->min_index = 0;
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] < piles->min)
		{
			piles->min = piles->p_a->pile[i];
			piles->min_index = i;
		}
		i++;
	}
}

int		small_pile(t_p *piles)
{
	if (piles->p_a->size == 1)
		return (TRUE);
	if (piles->p_a->size == 2)
	{
		if (piles->p_a->pile[0] > piles->p_a->pile[1])
			swap_a(piles->p_a, 1);
		return (TRUE);
	}
	return (FALSE);
}
