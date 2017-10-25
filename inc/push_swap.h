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
# define BUFF 2048

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
	int			max_index;
	int			min;
	int			min_index;
	int			index_to_sort;
	char		buffer[BUFF];
}				t_p;

/*
** Push_swap
*/
void	push_swap(t_p *piles);
int		small_pile(t_p *piles);

/*
** Small_sort.c
*/
int		sort_three(t_p *piles, int print);
int		sort_five(t_p *piles, int print);
void	get_max(t_p *piles);

/*
** Sort.c
*/
void	fill_b(t_p *piles, int pivot);
void	empty_b(t_p *piles);
void	get_next_sort_index(t_p *piles);
void	check_swap(t_p *piles);

/*
** Min.c
*/
void	move_min(t_p *piles, int index_to_place);
void	move_min_up(t_p *piles, int index_to_place);
void	move_min_down(t_p *piles, int index_to_place);
void	get_min(t_p *piles);
int		exist_smallest(t_p *piles, int pivot);

/*
** Parsing.c
*/
char	*get_arg(int argc, char **argv, char *arg);
char	**check_arg(char *arg);
int		set_pile(char **arg_tab, t_pile *pile_a, t_pile *pile_b, t_p *piles);
int		check_doublons(t_pile *pile);

/*
** Check_range.c
*/
int		check_int_range(char *nb);
int		check_int_min(char *nb);
int		check_int_max(char *nb);

/*
** Buff.c
*/
void	add_buffer(t_p *piles, char *instruction);
void	print_buffer(t_p *piles);

/*
** Checker.c
*/
void	checker(t_p *piles);

/*
** Exec.c
*/
void	exec_line(char *line, t_p *piles);
int		check(t_p *piles);

/*
** Rotate.c
*/
void	rotate_a(t_p *piles, int print);
void	rotate_b(t_p *piles, int print);
void	rotate_ab(t_p *piles, int print);

/*
** Reverse_rotate.c
*/
void	r_rotate_a(t_p *piles, int print);
void	r_rotate_b(t_p *piles, int print);
void	r_rotate_ab(t_p *piles, int print);

/*
** Swap.c
*/
void	swap_a(t_p *piles, int print);
void	swap_b(t_p *piles, int print);
void	swap_ab(t_p *piles, int print);

/*
** Push.c
*/
void	push_a(t_p *piles, int print);
void	push_b(t_p *piles, int print);

/*
** Utils.c
*/
void	swap_int(int *a, int *b);
void	ft_error(void);
void	print_tab(t_pile *pile);

/*
** Free_ressources.c
*/
void	free_ressources(t_p *piles, char **arg_tab, char *arg);
void	free_piles(t_p *piles);
void	free_arg(char **arg_tab);

#endif
