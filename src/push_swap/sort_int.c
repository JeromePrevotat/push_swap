/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_int.c		                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/*int		split(int *tab, int start, int end, int pivot)
{
	int	i;
	int j;

	if (pivot != end)
		swap_int(&tab[pivot], &tab[end]);
	j = start;
	i = start;
	while (i < end)
	{
		if (tab[i] < tab[end])
		{
			if (i != j)
				swap_int(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	if (end != j)
		swap_int(&tab[end], &tab[j]);
	return (j);
}

int		quicksort(int *tab, int start, int end)
{
	int pivot;

	pivot = start;
	if (start < end)
	{
		pivot = split(tab, start, end, pivot);
		quicksort(tab, start, pivot - 1);
		quicksort(tab, pivot + 1, end);
		return (1);
	}
	return (0);
}*/

/*int		split(t_p *piles, int start, int end, int pivot)
{
	int	i;
	int j;

	if (pivot != end)
		swap_int(&piles->p_a->pile[pivot], &piles->p_a->pile[end]);
	j = start;
	i = start;
	while (i < end)
	{
		if (piles->p_a->pile[i] < piles->p_a->pile[end])
		{
			if (i != j)
				swap_int(&piles->p_a->pile[i], &piles->p_a->pile[j]);
			j++;
		}
		i++;
	}
	if (end != j)
		swap_int(&piles->p_a->pile[end], &piles->p_a->pile[j]);
	return (j);
}*/

int		split(t_p *piles, int start, int end, int pivot)
{
	int		tmp;
	size_t	i;

	if (start == 0 && end == 1)
	{
		if (piles->p_a->pile[0] > piles->p_a->pile[1])
			swap_a(piles->p_a);
		return (0);
	}
	printf(GREEN"ENTERING SPLIT\nPivot : %d // start : %d // end : %d\n"RESET, piles->p_a->pile[pivot], start, end);
	tmp = piles->p_a->pile[pivot];
	if (pivot != end)
		rotate_a(piles->p_a);
	i = 0;
	while ((int)i < start)
	{
		rotate_a(piles->p_a);
		i++;
	}
	i = start;
	//while (piles->p_a->pile[0] != tmp)
	while ((int)i < end)
	{
		ft_putendl(YELLOW"\nPile A WHILE :"RESET);
		print_tab(piles->p_a);
		ft_putendl(YELLOW"\nPile B WHILE :"RESET);
		print_tab(piles->p_b);
		printf("TESTED : %d // SIZE A : %zu // I : %zu\n", piles->p_a->pile[0], piles->p_a->size, i);
		if (piles->p_a->pile[0] < tmp)
			push_b(piles->p_a, piles->p_b);
		else
			rotate_a(piles->p_a);
		i++;
	}
	printf(RED"END WHILE\n"RESET);
	if (i <= piles->p_a->size)
		r_rotate_a(piles->p_a);
	while (piles->p_b->size != 0)
		push_a(piles->p_a, piles->p_b);
	ft_putendl("Pile A :");
	print_tab(piles->p_a);
	ft_putendl("Pile B :");
	print_tab(piles->p_b);
	ft_putendl("EXITING SPLIT");
	ft_putchar('\n');
	i = 0;
	while (piles->p_a->pile[i] != tmp)
		i++;
	if ((int)i - 1 > start)
		return (i);
	return (0);
}

int		quicksort(t_p *piles, int start, int end)
{
	int pivot;
	static int nb_call = 1;

	if (nb_call > 10)
		exit(0);
	pivot = start;
	printf("NB_CALL : %d // PIVOT : %d\n", nb_call, piles->p_a->pile[pivot]);
	ft_putendl("Pile A :");
	print_tab(piles->p_a);
	ft_putendl("Pile B :");
	print_tab(piles->p_b);
	ft_putchar('\n');
	nb_call++;
	if (start < end)
	{
		pivot = split(piles, start, end, pivot);
		quicksort(piles, start, pivot - 1);
		quicksort(piles, pivot + 1, end);
		return (1);
	}
	return (0);
}
