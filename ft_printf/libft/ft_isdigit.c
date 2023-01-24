/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pwhittin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 09:47:14 by pwhittin          #+#    #+#             */
/*   Updated: 2022/12/07 17:04:36 by pwhittin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Checks to see if something is a number between 0 or 9. Not sure what else
 * to tell you really.*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
