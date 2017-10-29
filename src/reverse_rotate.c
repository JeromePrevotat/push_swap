/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	r_rotate_a(t_p *piles, int print, int verbal)
{
	size_t	i;

	if (!piles->p_a->pile || piles->p_a->size < 2)
		return ;
	i = piles->p_a->size - 1;
	while (i > 0)
	{
		swap_int(&piles->p_a->pile[i], &piles->p_a->pile[i - 1]);
		i--;
	}
	piles->min_index++;
	if ((size_t)piles->min_index == piles->p_a->size)
		piles->min_index = 0;
	if (print == 1)
		ft_putendl("rra");
	if (verbal == 1)
		print_piles(piles);
}

void	r_rotate_b(t_p *piles, int print, int verbal)
{
	size_t	i;

	if (!piles->p_b->pile || piles->p_b->size < 2)
		return ;
	i = piles->p_b->size - 1;
	while (i > 0)
	{
		swap_int(&piles->p_b->pile[i], &piles->p_b->pile[i - 1]);
		i--;
	}
	if (print == 1)
		ft_putendl("rrb");
	if (verbal == 1)
		print_piles(piles);
}

void	r_rotate_ab(t_p *piles, int print, int verbal)
{
	size_t	i;

	if (!piles->p_a->pile || piles->p_a->size < 2
		|| !piles->p_b->pile || piles->p_b->size < 2)
		return ;
	i = piles->p_a->size - 1;
	while (i > 0)
	{
		swap_int(&piles->p_a->pile[i], &piles->p_a->pile[i - 1]);
		i--;
	}
	piles->min_index++;
	if ((size_t)piles->min_index == piles->p_a->size)
		piles->min_index = 0;
	i = piles->p_b->size - 1;
	while (i > 0)
	{
		swap_int(&piles->p_b->pile[i], &piles->p_b->pile[i - 1]);
		i--;
	}
	if (print == 1)
		ft_putendl("rrr");
	if (verbal == 1)
		print_piles(piles);
}
