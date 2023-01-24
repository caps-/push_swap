/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:20:08 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:15:30 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* This guy figures out the cost of moving each element of stack b in to the
 * correct position in stack a. cost_a is the cost of getting to the correct
 * position in stack a, cost_b is the same but for stack b.
 *
 * One thing we do here is check to see if the element is in the top half or
 * the bottom half of the stack which we can figure out by checking to see if
 * the element is bigger or smaller than half of the total element size. If it's
 * smaller we multiply it by -1 to make it a negative number which will let us
 * quikcly know which half of the stack it's in when we use our moving funcs in
 * move_em.c. */
void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;
	int		size_a;
	int		size_b;

	tmp_a = *stack_a;
	tmp_b = *stack_b;
	size_a = get_stack_size(tmp_a);
	size_b = get_stack_size(tmp_b);
	while (tmp_b)
	{
		tmp_b->cost_b = tmp_b->pos;
		if (tmp_b->pos > size_b / 2)
			tmp_b->cost_b = (size_b - tmp_b->pos) * -1;
		tmp_b->cost_a = tmp_b->target_pos;
		if (tmp_b->target_pos > size_a / 2)
			tmp_b->cost_a = (size_a - tmp_b->target_pos) * -1;
		tmp_b = tmp_b->next;
	}
}

/* Finds the element in stack b with the chepest cost to move to stack a and
 * then moves it to the correct position. If the sum of both cost_a and cost_b
 * is less than whatever value is stored in the 'cheapest' variable then we know
 * THAT is now the cheapest, and assign that value accordingly before moving on
 * and trying it all again with the next elements. Once that's all done we can
 * finally move the stacks around at the cheapest cost. */
void	do_cheapest(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	tmp = *stack_b;
	cheapest = INT_MAX;
	while (tmp)
	{
		if (abs_val(tmp->cost_a) + abs_val(tmp->cost_b) < abs_val(cheapest))
		{
			cheapest = abs_val(tmp->cost_b) + abs_val(tmp->cost_a);
			cost_a = tmp->cost_a;
			cost_b = tmp->cost_b;
		}
		tmp = tmp->next;
	}
	move_em(stack_a, stack_b, cost_a, cost_b);
}
