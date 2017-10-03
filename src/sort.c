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

void	check_swap(t_p *piles)
{
	if (piles->p_a->size >= 2 && piles->p_b->size >= 2
		&& piles->p_a->pile[0] > piles->p_a->pile[1]
		&& piles->p_a->pile[1] != piles->min
		&& piles->p_b->pile[0] < piles->p_b->pile[1])
		swap_ab(piles->p_a, piles->p_b, 1);
	else if (piles->p_a->pile[0] > piles->p_a->pile[1]
		&& piles->p_a->pile[1] != piles->min)
		swap_a(piles->p_a, 1);
	else if (piles->p_b->pile[0] < piles->p_b->pile[1])
		swap_b(piles->p_b, 1);
}
