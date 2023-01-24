/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 17:51:08 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:16:24 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Swaps the top two elements of a stack and does nothing if there's one or no
 * elements. */
static void	swap(t_stack *stack)
{
	int	tmp;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = tmp;
	tmp = stack->index;
	stack->index = stack->next->index;
	stack->next->index = tmp;
}

/* Swap the top two elements of stack a. */
void	do_sa(t_stack **stack_a)
{
	swap(*stack_a);
	ft_printf("sa\n");
}

/* Swap the top two elements of stack b. */
void	do_sb(t_stack **stack_b)
{
	swap(*stack_b);
	ft_printf("sb\n");
}

/* Swap the top two elements of stack and and stack b. */
void	do_ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_printf("ss\n");
}
