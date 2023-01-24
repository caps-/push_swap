/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:22:24 by pwhittin          #+#    #+#             */
/*   Updated: 2022/12/13 17:06:45 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Free each element in any given stack and resets the stack pointer to null.*/
void	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

/* Frees up the stacks and writes "Error" to the standard output and exits the
 * program with standard error code 0. I had this originally as exit (1) but
 * for some fuckin reason one of the testers INSISTED that all exit errors are
 * to return 0, so ..yeah. */
void	exit_error(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_a == NULL || *stack_a != NULL)
		free_stack(stack_a);
	if (stack_b == NULL || *stack_b != NULL)
		free_stack(stack_b);
	write(2, "Error\n", 6);
	exit (0);
}

/* Returns the absolute value of a number. We're going to use this to measure
 * the 'distance' of that number from 0 in either direction along the number
 * line. */
int	abs_val(int n)
{
	if (n < 0)
		return (n * -1);
	return (n);
}

/* A new atoi implementation. I would have used ft_atoi in libft but we need to
 * use our is_digit() function to make it work for this project so it's been
 * re-written here. Check is_digit() in input_utils.c for info on that guy.*/
long int	new_atoi(const char *str)
{
	long int	n;
	int			i;
	int			sign;

	n = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (is_digit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n * sign);
}
