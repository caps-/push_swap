/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 16:59:38 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:15:50 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Fill di ting deh. First up we convert the number passed to the program to an
 * integer using our new_atoi() function. If it's some sort of bullshit value we
 * just exit the program. Next up, we take the first number (i == 1) passed to
 * the function (argv[1]) and use that to create a new element in stack a before
 * incrementing i to move on to the next number. Once we're past that first one
 * we make a new element for each successive number and add them to the bottom
 * of stack_a as we find them. Once all of THAT is done we return our freshly
 * filled stack. */
t_stack	*fill_stack(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	n;
	int			i;

	stack_a = NULL;
	n = 0;
	i = 1;
	while (i < argc)
	{
		n = new_atoi(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
			exit_error(&stack_a, NULL);
		if (i == 1)
			stack_a = new_element((int)n);
		else
			stack_add_bottom(&stack_a, new_element((int)n));
		i++;
	}
	return (stack_a);
}

/* Function to index each number in the stack. Doing this means instead of
 * checking and comparing values we can just do it using the indexes. We'll use
 * stack_size here for the highest/top index amd we'll set the  lowest/bottom 
 * index to 1.
 *
 * We start by decrementing down though stack_size, which was passed to the
 * function from the main push_swap function. We've got a ptr variable to move
 * through the stack, as well as a variable called 'value' that will hold the
 * actual number that needs to be indexed.  */
void	make_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
