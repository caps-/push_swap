/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:59:36 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 13:01:23 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Assign a position in the index for each element of the stack from top to
 * bottom in ascending order. Position just means where it is in the stack, we
 * just numbering each element basically. */
static void	get_position(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while (tmp)
	{
		tmp->pos = i;
		tmp = tmp->next;
		i++;
	}
}

/* This thing finds the current position of the element with the lowest index
 * inside a stack. Remember that the indexes should be in ascending order, so the
 * smallest index is at the top, biggest index is at the bottom. It's a
 * recursive function that checks to see if the current index is less than the
 * lowest index.
 *
 * If the current index is less than the lowest index it means the the current
 * index IS now the lowest index. We stick it in lowest_index, then set the
 * lowest_pos variable to tmp->pos so we can move on to the next one and do 
 * the loop again. Once we've moved through all the elements/indexes we return
 * the lowest position. */
int	get_lowest_index_pos(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_index;
	int		lowest_pos;

	tmp = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = tmp->pos;
	while (tmp)
	{
		if (tmp->index < lowest_index)
		{
			lowest_index = tmp->index;
			lowest_pos = tmp->pos;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

/* Gets the best target position in stack a for a given index of an element in
 * stack b. We'll want to see if we can stick the index from stack b somewhere
 * in between two indexes in stack a, she first while loop checks to see there's 
 * an element in stack a with a bigger index than the index of the element we 
 * want to move in stack b.  */
static int	get_target(t_stack **a, int b_idx, int target_idx, int target_pos)
{
	t_stack	*tmp_a;

	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index > b_idx && tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	if (target_idx != INT_MAX)
		return (target_pos);
	tmp_a = *a;
	while (tmp_a)
	{
		if (tmp_a->index < target_idx)
		{
			target_idx = tmp_a->index;
			target_pos = tmp_a->pos;
		}
		tmp_a = tmp_a->next;
	}
	return (target_pos);
}

/* Gives a target position to each element in stack a, a target being the spot
 * that the current element from stack b needs to go for everything to be in the
 * right order. Each position is also used to figure out the cost of moving each
 * element to it's target position. */
void	get_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp_b;
	int		target_pos;

	tmp_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	target_pos = 0;
	while (tmp_b)
	{
		target_pos = get_target(stack_a, tmp_b->index, INT_MAX, target_pos);
		tmp_b->target_pos = target_pos;
		tmp_b = tmp_b->next;
	}
}
