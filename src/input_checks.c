/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 14:43:52 by pwhittin          #+#    #+#             */
/*   Updated: 2023/01/24 16:14:02 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Checks to make sure only numbers have been passed to the program. Nothing
 * particularly crazy here. */
static int	onlynumbers(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

/* Checks for duplicate numbers. Nothing crazy, just moves through the args 
 * and runs the number_compare() function from our input utils which will
 * return 0 to this function if it finds a match. If that's the case we then
 * return 1 to indicate we've found duplicates, otherwise we return 0. */
static int	duplicates(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 1;
		while (argv[j])
		{
			if (j != i && number_compare(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/* Does what it says on the tin. Also checks to see if the number is just 0,
 * or 00, or 0000 or whatever and NOT something like 03 or 010 or whatever.
 * Also makes sure it's not -0 or +0 or something dumb like that too. Returns
 * 1 if the argument is zero  so our correct_input() function can add it to the
 * zero count. */
static int	find_zeros(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

/* OK so this function checks to make sure the program has been given the right
 * input, which needs to be numbers. We go in to a while loop first, and if the 
 * input is literally not a number we'll return 0. Then we check to see if the
 * user has passed a zero to the program using our arg_is_zero() function and
 * then add 1 to our zero count if it is. Once the loop is done we check our
 * zero count, and if there's any in there we return 0. Next we check to see
 * if there's any duplicates, and again return 0 if there is.
 *
 * Also after typing all this out the word "zero" looks really weird and wrong.
 * Like when you say a word over and over again until it looses any semantic
 * meaning and just becomes completely abstracted sound. Zeros is even worse,
 * it just looks like a Greek name to me now. Zeros Stefanopoulos. Fuck. */
int	correct_input(char **argv)
{
	int	i;
	int	zero_count;

	zero_count = 0;
	i = 1;
	while (argv[i])
	{
		if (!onlynumbers(argv[i]))
			return (0);
		zero_count += find_zeros(argv[i]);
		i++;
	}
	if (zero_count > 1)
		return (0);
	if (duplicates(argv))
		return (0);
	return (1);
}
