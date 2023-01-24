/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_em.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:26:26 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:17:03 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Pushes all the elements of stack a in to stack b except for the last three.
 * If the elements are smaller (less than half the size of the total stack) they
 * get pushesd first, followed by the larger ones.*/
static void	push_all_but_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	i;

	stack_size = get_stack_size(*stack_a);
	pushed = 0;
	i = 0;
	while (stack_size > 6 && i < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			do_pb(stack_a, stack_b);
			pushed++;
		}
		else
			do_ra(stack_a);
		i++;
	}
	while (stack_size - pushed > 3)
	{
		do_pb(stack_a, stack_b);
		pushed++;
	}
}

/* Shifts the stack around until the lowest value is at the top. If it's in the
 * bottom half we'll reverse rotate it, otherwise rotate it until it's at the
 * top of the stack. */
static void	shift_stack(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = get_stack_size(*stack_a);
	lowest_pos = get_lowest_index_pos(stack_a);
	if (lowest_pos > stack_size / 2)
	{
		while (lowest_pos < stack_size)
		{
			do_rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			do_ra(stack_a);
			lowest_pos--;
		}
	}
}

/* Sorting algo for stacks larger than three elements. We start out by pushing
 * all but three numbers to stack b for further sorting, then run our other
 * likkle_sort() funciton on the three numbers left in a to get them all in the
 * correct ascending order. Next up we need to figure out the cheapest move to
 * do to to sort everything out, so we'll use some functions to find a target
 * position in stack a, figure out the cost of moving each element from stack b
 * in to the targets in stack a, and then do it using the cheapest move.*/
void	sort_em(t_stack **stack_a, t_stack **stack_b)
{
	push_all_but_three(stack_a, stack_b);
	likkle_sort(stack_a);
	while (*stack_b)
	{
		get_target_pos(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest(stack_a, stack_b);
	}
	if (!already_sorted(*stack_a))
		shift_stack(stack_a);
}
