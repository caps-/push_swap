/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   likkle_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 16:47:21 by pwhittin          #+#    #+#             */
/*   Updated: 2022/12/13 20:01:58 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Finds and returns the highest index in a stack. */
static int	highest_index(t_stack *stack)
{
	int	index;

	index = stack->index;
	while (stack)
	{
		if (stack->index > index)
			index = stack->index;
		stack = stack->next;
	}
	return (index);
}

/* Sorts a stack of 3 numbers in 2 moves or less. */
void	likkle_sort(t_stack **stack)
{
	int	highest;

	if (already_sorted(*stack))
		return ;
	highest = highest_index(*stack);
	if ((*stack)->index == highest)
		do_ra(stack);
	else if ((*stack)->next->index == highest)
		do_rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		do_sa(stack);
}
