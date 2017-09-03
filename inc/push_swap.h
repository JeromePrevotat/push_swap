/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h	                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jprevota <jprevota@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 17:25:58 by jprevota          #+#    #+#             */
/*   Updated: 2017/06/19 17:25:58 by jprevota         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define TRUE 1
# define FALSE 0
# define ERROR -1

# include <stdio.h>
# include "../libft/libft.h"

typedef struct	s_pile
{
	size_t		size;
	int			*pile;
}				t_pile;

//Push_swap
void	push_swap(t_pile *pile_a, t_pile *pile_b);

//Sort_int.c
//int		split(int *tab, int start, int end, int pivot);
//int		quicksort(int *tab, int start, int end);
int		split(t_pile *pile_a, int start, int end, int pivot);
int		quicksort(t_pile *pile_a, int start, int end, t_pile *pile_b);

//Parsing.c
char	*get_arg(int argc, char **argv, char *arg);
char	**check_arg(char *arg);
int		set_pile(char **arg_tab, t_pile *pile_a, t_pile *pile_b);
int		check_doublons(t_pile *pile);

//Rotate.c
void	rotate_a(t_pile *pile_a);
void	rotate_b(t_pile *pile_b);
void	rotate_ab(t_pile *pile_a, t_pile *pile_b);

//Reverse_rotate.c
void	r_rotate_a(t_pile *pile_a);
void	r_rotate_b(t_pile *pile_b);
void	r_rotate_ab(t_pile *pile_a, t_pile *pile_b);

//Swap.c
void	swap_a(t_pile *pile_a);
void	swap_b(t_pile *pile_b);
void	swap_ab(t_pile *pile_a, t_pile *pile_b);

//Push.c
void	push_a(t_pile *pile_a, t_pile *pile_b);
void	push_b(t_pile *pile_a, t_pile *pile_b);

//Utils.c
void	swap_int(int *a, int *b);
void	print_tab(t_pile *pile);
void	ft_error(void);

#endif
