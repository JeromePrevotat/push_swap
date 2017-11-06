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

void	get_next_sort_index(t_p *piles)
{
	int	i;

	i = 1;
	if (piles->p_a->pile[0] == piles->min
		|| (size_t)piles->index_to_sort == piles->p_a->size)
		return ;
	while ((size_t)i < piles->p_a->size - piles->index_to_sort
		&& piles->p_a->pile[i] != piles->min)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[0])
			return ;
		i++;
	}
	piles->index_to_sort++;
}

void	empty_b(t_p *piles, int verbal)
{
	while (piles->p_b->size > 0)
	{
		check_swap(piles, verbal);
		push_a(piles, 1, verbal);
	}
	rotate_a(piles, 1, verbal);
	piles->index_to_sort++;
}

void	fill_b(t_p *piles, int pivot, int verbal)
{
	while (exist_smallest(piles, pivot) == TRUE)
	{
		if (piles->p_a->pile[0] < pivot)
			push_b(piles, 1, verbal);
		else
			rotate_a(piles, 1, verbal);
	}
}

void	check_swap(t_p *piles, int verbal)
{
	if (piles->p_a->size >= 2 && piles->p_b->size >= 2
		&& piles->p_a->pile[0] > piles->p_a->pile[1]
		&& piles->p_a->pile[1] != piles->min
		&& piles->p_b->pile[0] < piles->p_b->pile[1])
		swap_ab(piles, 1, verbal);
	else if (piles->p_a->pile[0] > piles->p_a->pile[1]
		&& piles->p_a->pile[1] != piles->min)
		swap_a(piles, 1, verbal);
	else if (piles->p_b->pile[0] < piles->p_b->pile[1])
		swap_b(piles, 1, verbal);
}
