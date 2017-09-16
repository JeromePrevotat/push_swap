/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c	   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	find_max(t_p *piles)
{
	size_t	i;

	i = 0;
	piles->max = piles->p_a->pile[0];
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] > piles->max)
			piles->max = piles->p_a->pile[i];
		i++;
	}
}

void	find_min(t_p *piles)
{
	size_t	i;

	i = 0;
	piles->min = piles->p_a->pile[0];
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] < piles->min)
			piles->min = piles->p_a->pile[i];
		i++;
	}
}

int		new_min_index(t_p *piles)
{
	size_t	i;

	i = piles->min_index;
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] > piles->p_a->pile[i + 1])
			return (i);
		i++;
	}
	return (i);
}

void	new_min(t_p *piles)
{
	size_t	i;
	int		min;

	i = piles->min_index;
	min = piles->p_a->pile[i];
	while (i < piles->p_a->size)
	{
		if (piles->p_a->pile[i] < min)
			min = piles->p_a->pile[i];
		i++;
	}
	piles->min = min;
}

int	check(t_p *piles)
{
	size_t	i;

	i = 1;
	while (i < piles->p_a->size - 1)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[i - 1] || piles->p_a->pile[i] > piles->p_a->pile[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	print_tab(t_pile *pile)
{
	size_t	i;

	i = 0;
	while (i < pile->size)
	{
		ft_putnbr(pile->pile[i]);
		ft_putstr(" // ");
		i++;
	}
	ft_putchar('\n');
}

void	swap_int(int *a, int *b)
{
	int tmp;

	if (a && b)
	{
		tmp = *a;
		*a = *b;
		*b = tmp;
	}
}

/*void	swap_int(int *a, int *b)
{
	if (a && b)
	{
		*a = *a - *b;
		*b = *a + *b;
		*a = *b - *a;
	}
}*/

void ft_error(void)
{
	ft_putendl("Error");
	exit(0);
}
