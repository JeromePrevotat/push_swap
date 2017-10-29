/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

char	*get_arg(int argc, char **argv, char *arg)
{
	int		i;
	size_t	total_size;

	i = 1;
	total_size = argc;
	while (i < argc)
	{
		total_size = total_size + ft_strlen(argv[i]);
		i++;
	}
	if (!(arg = (char *)malloc(total_size * sizeof(char))))
		return (NULL);
	ft_memset(arg, '\0', total_size);
	i = 1;
	while (i < argc)
	{
		arg = ft_strcat(arg, argv[i]);
		arg = ft_strcat(arg, " ");
		i++;
	}
	return (arg);
}

char	**check_arg(char *arg)
{
	int		i;
	int		j;
	char	**arg_tab;

	i = 0;
	arg_tab = ft_strsplit(arg, ' ');
	while (arg_tab[i] != NULL)
	{
		j = 0;
		while (arg_tab[i][j] != '\0')
		{
			if (j == 0 && (arg_tab[i][j] == '-' || arg_tab[i][j] == '+'))
				j++;
			if (ft_isdigit(arg_tab[i][j]) == FALSE)
				return (NULL);
			j++;
		}
		i++;
	}
	return (arg_tab);
}

int		set_pile(char **arg_tab, t_pile *pile_a, t_pile *pile_b, t_p *piles)
{
	size_t	i;
	size_t	arg_size;

	i = 0;
	arg_size = 0;
	while (arg_tab[arg_size] != NULL)
		arg_size++;
	pile_a->size = arg_size;
	pile_b->size = 0;
	if (!(pile_a->pile = (int *)malloc(arg_size * sizeof(int)))
		|| !(pile_b->pile = (int *)malloc(arg_size * sizeof(int))))
		return (ERROR);
	ft_memset(pile_a->pile, '\0', arg_size);
	ft_memset(pile_b->pile, '\0', arg_size);
	ft_memset(piles->buffer, '\0', BUFF);
	if (init_p_a(arg_tab, pile_a) == ERROR)
		return (ERROR);
	if (check_doublons(pile_a) == ERROR)
		return (ERROR);
	piles->p_a = pile_a;
	piles->p_b = pile_b;
	return (TRUE);
}

int		init_p_a(char **arg_tab, t_pile *pile_a)
{
	size_t	i;

	i = 0;
	while (i < pile_a->size)
	{
		if (check_int_range(arg_tab[i]) == FALSE)
			return (ERROR);
		pile_a->pile[i] = ft_atoi(arg_tab[i]);
		i++;
	}
	return (TRUE);
}

int		check_doublons(t_pile *pile)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < pile->size - 1)
	{
		j = i + 1;
		while (j < pile->size)
		{
			if (pile->pile[j] == pile->pile[i])
				return (ERROR);
			j++;
		}
		i++;
	}
	return (TRUE);
}
