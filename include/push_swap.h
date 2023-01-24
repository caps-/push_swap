/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:27:29 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:29:08 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/includes/libftprintf.h"
# include <limits.h>

/*
 Colours for use with ft_printf. Never used them because the checkers we use
 for this project seem to actually read these codes which makes it look like
 it's outputting the wrong thing, ie not just "rrb" or whatever it's sposed to
 be.
# define RED   "\x1B[31m"
# define GRN   "\x1B[32m"
# define YEL   "\x1B[33m"
# define BLU   "\x1B[34m"
# define MAG   "\x1B[35m"
# define CYN   "\x1B[36m"
# define WHT   "\x1B[37m"
# define RESET "\x1B[0m"

 cause I'm not sure I'm allowed to use limits.h
# define INT_MIN	(-INT_MAX - 1)
# define INT_MAX	2147483647
*/

/* Stack structure */
typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

/* Init stuff */
t_stack		*fill_stack(int argc, char **argv);
void		make_index(t_stack *stack_a, int stack_size);

/* Sorting algos */
int			already_sorted(t_stack *stack);
void		likkle_sort(t_stack **stack);
void		sort_em(t_stack **stack_a, t_stack **stack_b);

/* Position stuff */
int			get_lowest_index_pos(t_stack **stack);
void		get_target_pos(t_stack **stack_a, t_stack **stack_b);

/* Cost stuff */
void		get_cost(t_stack **stack_, t_stack **stack_b);
void		do_cheapest(t_stack **stack_a, t_stack **stack_b);

/* Calculate moves */
void		move_em(t_stack **a, t_stack **b, int cost_a, int cost_b);

/* Rotations */
void		do_pa(t_stack **stack_a, t_stack **stack_b);
void		do_pb(t_stack **stack_a, t_stack **stack_b);
void		do_sa(t_stack **stack_a);
void		do_sb(t_stack **stack_b);
void		do_ss(t_stack **stack_a, t_stack **stack_b);
void		do_ra(t_stack **stack_a);
void		do_rb(t_stack **stack_b);
void		do_rr(t_stack **stack_a, t_stack **stack_b);
void		do_rra(t_stack **stack_a);
void		do_rrb(t_stack **stack_b);
void		do_rrr(t_stack **stack_a, t_stack **stack_b);

/* Stack functions */
t_stack		*last_element(t_stack *stack);
t_stack		*second_to_last(t_stack *stack);
t_stack		*new_element(int value);
void		stack_add_bottom(t_stack **stack, t_stack *new);
int			get_stack_size(t_stack *stack);

/* Utils */
void		free_stack(t_stack **stack);
void		exit_error(t_stack **stack_a, t_stack **stack_b);
int			abs_val(int n);
long int	new_atoi(const char *str);

/* Input utils */
int			correct_input(char **argv);
int			is_sign(char c);
int			number_compare(const char *s1, const char *s2);
int			is_digit(char c);

#endif
