/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

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

/*void	new_min_index(t_p *piles)
{
	size_t	i;

	if ((size_t)piles->min_index == piles->p_a->size - 1)
		return;
	piles->min_index++;
	i = piles->min_index + 1;
	while (i < piles->p_a->size - 1)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[piles->min_index])
			return ;
		i++;
	}
	new_min_index(piles);
}*/

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
	write(2, "Error\n", 6);
	exit(0);
}

void	free_ressources(t_p *piles, char **arg_tab, char *arg)
{
	int	i;

	i = 0;
	free_piles(piles);
	free_arg(arg_tab);
	if (arg != NULL)
		free(arg);
}

void	free_piles(t_p *piles)
{
	if (piles == NULL)
		return ;
	if (piles->p_a->pile != NULL)
		free(piles->p_a->pile);
	if (piles->p_a != NULL)
		free(piles->p_a);
	if (piles->p_b->pile != NULL)
		free(piles->p_b->pile);
	if (piles->p_b != NULL)
		free(piles->p_b);
	free(piles);
}

void	free_arg(char **arg_tab)
{
	int	i;

	i = 0;
	while (arg_tab[i] != NULL)
	{
		free(arg_tab[i]);
		i++;
	}
	free(arg_tab);
}
