/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		main(int argc, char **argv)
{
	int	verbal;

	verbal = FALSE;
	if (argc == 2 && ft_strcmp(argv[1], "-v") == 0)
		ft_error();
	else if (argc >= 2)
	{
		verbal = verbal_mode(argv);
		parse(argc, argv, verbal);
	}
	else
		ft_error();
	return (0);
}

void	push_swap(t_p *piles, int verb)
{
	int	pivot;

	get_min(piles);
	if (check_piles_sorted(piles) == FALSE)
	{
		if (piles->p_a->size <= 5)
			small_pile(piles, verb);
		else
		{
			piles->index_to_sort = 1;
			while ((size_t)piles->index_to_sort != piles->p_a->size)
			{
				move_min(piles, piles->p_a->size - piles->index_to_sort, verb);
				pivot = piles->p_a->pile[0];
				push_b(piles, 1, verb);
				fill_b(piles, pivot, verb);
				move_min(piles, piles->p_a->size - piles->index_to_sort, verb);
				r_rotate_b(piles, 1, verb);
				empty_b(piles, verb);
				get_next_sort_index(piles);
			}
			move_min(piles, 0, verb);
		}
	}
}

int		parse(int argc, char **argv, int verbal)
{
	t_p		*piles;
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**arg_tab;
	char	*arg;

	arg = NULL;
	arg = get_arg(argc, argv, arg, 1 + verbal);
	if ((arg_tab = check_arg(arg)) == NULL)
		ft_error();
	if (!(piles = (t_p *)malloc(1 * sizeof(t_p)))
		|| !(pile_a = (t_pile *)malloc(1 * sizeof(t_pile)))
		|| !(pile_b = (t_pile *)malloc(1 * sizeof(t_pile))))
		return (ERROR);
	if (set_pile(arg_tab, pile_a, pile_b, piles) == ERROR)
		ft_error();
	push_swap(piles, verbal);
	free_ressources(piles, arg_tab, arg);
	return (TRUE);
}

int		small_pile(t_p *piles, int verbal)
{
	if (piles->p_a->size == 1)
		return (TRUE);
	if (piles->p_a->size == 2)
	{
		if (piles->p_a->pile[0] > piles->p_a->pile[1])
			swap_a(piles, 1, verbal);
		return (TRUE);
	}
	if (piles->p_a->size == 3)
		return (sort_three(piles, 1, verbal));
	if (piles->p_a->size == 4 || piles->p_a->size == 5)
		return (sort_five(piles, 1, verbal));
	return (FALSE);
}
