/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <pwhittin@student.42adel.org.au>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 14:49:03 by pwhittin          #+#    #+#             */
/*   Updated: 2022/12/13 17:08:22 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* A quick re-implementation of ft_isdigit from libft. Basically the same, but
 * it accepts a char rather than an int. */
int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/* Quick little function to check if the character being passed is a sign,
 * either '+' or '-'. Returns 1 if it is, 0 if it isn't. */
int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

/* Compares two strings of digits to check if they're the same or not. It
 * ignores any + signs so that +10 == 10, but -10 !- 10 or whatever. Then it
 * goes in to a while loop that checks to see if both strings aren't null
 * terminators and both have matching numbers. Then just a bit of arithmetic
 * to give a return value; if they're the same then subtracting one from the
 * other gives us a 0 to return, signalling a match. */
int	number_compare(const char *s1, const char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = i;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] != '\0' && s2[j] != '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}
