/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
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

typedef struct	s_p
{
	t_pile		*p_a;
	t_pile		*p_b;
	int			max;
	int			min;
	int			min_index;
	int			index_to_sort;
}				t_p;

//Sort.c
int		small_pile(t_p *piles);
void	move_min(t_p *piles, int index_to_place);
void	get_min(t_p *piles);
void	move_min_up(t_p *piles, int index_to_place);
void	move_min_down(t_p *piles, int index_to_place);
int		exist_smallest(t_p *piles, int pivot);
void	fill_b(t_p *piles, int pivot);
void	empty_b(t_p *piles);
void	get_next_sort_index(t_p *piles);

//Push_swap
void	push_swap(t_p *piles);

//Checker.c
void	checker(t_p *piles);

//Exec.c
void	exec_line(char *line, t_p *piles);

//Sort_int.c
void	sort_piles(t_p *piles);
void	start_sort(t_p *piles);
int	check_inf(t_p *piles, int pivot);
void reset(t_p *piles);
void check_swap(t_p *piles);
void find_index(t_p *piles, size_t start);
void push_front(t_p *piles);
int	check_piles(t_p *piles);

//Parsing.c
char	*get_arg(int argc, char **argv, char *arg);
char	**check_arg(char *arg);
int		set_pile(char **arg_tab, t_pile *pile_a, t_pile *pile_b, t_p *piles);
int		check_doublons(t_pile *pile);

//Rotate.c
//void	rotate_a(t_pile *pile_a, int print);
void	rotate_a(t_p *piles, int print);
//void	rotate_b(t_pile *pile_b, int print);
void	rotate_b(t_p *piles, int print);
//void	rotate_ab(t_pile *pile_a, t_pile *pile_b, int print);
void	rotate_ab(t_p *piles, int print);

//Reverse_rotate.c
//void	r_rotate_a(t_pile *pile_a, int print);
void	r_rotate_a(t_p *piles, int print);
//void	r_rotate_b(t_pile *pile_b, int print);
void	r_rotate_b(t_p *piles, int print);
//void	r_rotate_ab(t_pile *pile_a, t_pile *pile_b, int print);
void	r_rotate_ab(t_p *piles, int print);

//Swap.c
void	swap_a(t_pile *pile_a, int print);
void	swap_b(t_pile *pile_b, int print);
void	swap_ab(t_pile *pile_a, t_pile *pile_b, int print);

//Push.c
//void	push_a(t_pile *pile_a, t_pile *pile_b, int print);
void	push_a(t_p *piles, int print);
//void	push_b(t_pile *pile_a, t_pile *pile_b, int print);
void	push_b(t_p *piles, int print);

//Reset.c
//void	reset(t_p *piles);

//Utils.c
void	find_max(t_p *piles);
void	find_min(t_p *piles);
void	new_min(t_p *piles);
void	new_min_index(t_p *piles);
int		check(t_p *piles);
void	swap_int(int *a, int *b);
void	print_tab(t_pile *pile);
void	ft_error(void);
void	free_ressources(t_p *piles, char **arg_tab, char *arg);
void	free_piles(t_p *piles);
void	free_arg(char **arg_tab);

#endif
