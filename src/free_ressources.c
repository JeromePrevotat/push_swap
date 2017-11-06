/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
