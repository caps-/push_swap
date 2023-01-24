/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:31:52 by pwhittin          #+#    #+#             */
/*   Updated: 2022/12/07 16:18:38 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Quick function to check if the stack is already sorted. If the current value
 * (hehehe) is bigger than the one after it we know that the stack isn't sorted
 * so we return 0, otherwise we return 1 if it is. */
int	already_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* Picks a sorting method depending on the number of values it needs to sort.*/
static void	push_swap(t_stack **stack_a, t_stack **stack_b, int stacksize)
{
	if (stacksize == 2 && !already_sorted(*stack_a))
		do_sa(stack_a);
	else if (stacksize == 3)
		likkle_sort(stack_a);
	else if (stacksize > 3 && !already_sorted(*stack_a))
		sort_em(stack_a, stack_b);
}

/* First up we check to make sure the program has been given the correct input,
 * and exits with an error message if it hasn't. If the correct input has been
 * given we initialize the stacks, index the values in stack a as well as get
 * it's size, then send them off to to get pushed and swapped. Once they've
 * been sorted we free the stacks and exit the program. */
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stacksize;

	if (argc < 2)
		return (0);
	if (!correct_input(argv))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = fill_stack(argc, argv);
	stacksize = get_stack_size(stack_a);
	make_index(stack_a, stacksize + 1);
	push_swap(&stack_a, &stack_b, stacksize);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
