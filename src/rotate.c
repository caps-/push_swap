/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:51:22 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:16:49 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps/rotates the top and last elements of a stack.
 *
 * [1]				[2]
 * [2]	 becomes	[3]
 * [3]				[1]
 *
 * First we copy the pointer to the stack to our tmp variable so we can use it
 * later. Next we move to the next element of the actual stack so we don't mess
 * with the values between the top and last and then we put the value for the 
 * last element in the first spot. After that we null the next element in our
 * tmp stack so there's only the first element left in it, it's basically
 * disconnecting the first one from the rest. Finally we set the last element
 * to the the single one that's now stored in tmp. */
static void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = *stack;
	*stack = (*stack)->next;
	last = last_element(*stack);
	tmp->next = NULL;
	last->next = tmp;
}

/* Rotates stack a */
void	do_ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

/* Rotates stack b */
void	do_rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

/* Rotates stack a and stack b */
void	do_rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_printf("rr\n");
}
