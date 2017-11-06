/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_a(t_p *piles, int print, int verbal)
{
	int	tmp;

	if (!piles->p_a->pile || piles->p_a->size < 2)
		return ;
	tmp = piles->p_a->pile[0];
	piles->p_a->pile[0] = piles->p_a->pile[1];
	piles->p_a->pile[1] = tmp;
	if (print == 1)
		ft_putendl("sa");
	if (verbal == 1)
		print_piles(piles);
}

void	swap_b(t_p *piles, int print, int verbal)
{
	int	tmp;

	if (!piles->p_b->pile || piles->p_b->size < 2)
		return ;
	tmp = piles->p_b->pile[0];
	piles->p_b->pile[0] = piles->p_b->pile[1];
	piles->p_b->pile[1] = tmp;
	if (print == 1)
		ft_putendl("sb");
	if (verbal == 1)
		print_piles(piles);
}

void	swap_ab(t_p *piles, int print, int verbal)
{
	int	tmp;

	if (!piles->p_a->pile || piles->p_a->size < 2
		|| !piles->p_b->pile || piles->p_b->size < 2)
		return ;
	tmp = piles->p_a->pile[0];
	piles->p_a->pile[0] = piles->p_a->pile[1];
	piles->p_a->pile[1] = tmp;
	tmp = piles->p_b->pile[0];
	piles->p_b->pile[0] = piles->p_b->pile[1];
	piles->p_b->pile[1] = tmp;
	if (print == 1)
		ft_putendl("ss");
	if (verbal == 1)
		print_piles(piles);
}
