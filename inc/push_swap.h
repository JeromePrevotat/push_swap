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

#define RED		"\x1B[31m"
#define GREEN	"\x1B[32m"
#define YELLOW	"\x1B[33m"
#define BLUE	"\x1B[34m"
#define MAGENTA	"\x1B[35m"
#define CYAN	"\x1B[36m"
#define WHITE	"\x1B[37m"
#define RESET	"\x1B[0m"

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
}				t_p;

//Push_swap
void	push_swap(t_p *piles);

//Checker.c
void	checker(t_p *piles);

//Exec.c
void	exec_line(char *line, t_p *piles);

//Sort_int.c
void	sort_piles(t_p *piles);
void	start_sort(t_p *piles);

//Parsing.c
char	*get_arg(int argc, char **argv, char *arg);
char	**check_arg(char *arg);
int		set_pile(char **arg_tab, t_pile *pile_a, t_pile *pile_b, t_p *piles);
int		check_doublons(t_pile *pile);

//Rotate.c
void	rotate_a(t_pile *pile_a, int print);
void	rotate_b(t_pile *pile_b, int print);
void	rotate_ab(t_pile *pile_a, t_pile *pile_b, int print);

//Reverse_rotate.c
void	r_rotate_a(t_pile *pile_a, int print);
void	r_rotate_b(t_pile *pile_b, int print);
void	r_rotate_ab(t_pile *pile_a, t_pile *pile_b, int print);

//Swap.c
void	swap_a(t_pile *pile_a, int print);
void	swap_b(t_pile *pile_b, int print);
void	swap_ab(t_pile *pile_a, t_pile *pile_b, int print);

//Push.c
void	push_a(t_pile *pile_a, t_pile *pile_b, int print);
void	push_b(t_pile *pile_a, t_pile *pile_b, int print);

//Reset.c
void	reset(t_p *piles);

//Utils.c
void	find_max(t_p *piles);
void	find_min(t_p *piles);
void	new_min(t_p *piles);
void	new_min_index(t_p *piles);
int		check(t_p *piles);
void	swap_int(int *a, int *b);
void	print_tab(t_pile *pile);
void	ft_error(void);

#endif
