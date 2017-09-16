/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		   	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_p		*piles;
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**arg_tab;
	char	*arg;

	arg = NULL;
	if (argc < 2)
		exit(0);
	else
	{
		arg = get_arg(argc, argv, arg);
		if ((arg_tab = check_arg(arg)) == NULL)
			ft_error();
		if(!(piles = (t_p *)malloc(1 * sizeof(t_p)))
			|| !(pile_a = (t_pile *)malloc(1 * sizeof(t_pile)))
			|| !(pile_b = (t_pile *)malloc(1 * sizeof(t_pile))))
			return (ERROR);
		if (set_pile(arg_tab, pile_a, pile_b, piles) == ERROR)
			ft_error();
		push_swap(piles);
	}
	if (arg != NULL)
		free(arg);
	return (0);
}

void push_swap(t_p *piles)
{
	size_t	i;

	if (piles->p_a->size == 1)
		return ;
	if (piles->p_a->size == 2)
	{
		if (piles->p_a->pile[0] > piles->p_a->pile[1])
			swap_a(piles->p_a, 1);
		else
			return ;
	}
	find_max(piles);
	find_min(piles);
	piles->min_index = 0;
	i = 0;
	sort_piles(piles);
}
