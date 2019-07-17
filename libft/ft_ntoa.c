/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ntoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/16 13:47:07 by kmira             #+#    #+#             */
/*   Updated: 2019/07/16 14:32:04 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
** 		Number to ascii function.
**
** 	The first paramerter is the value that is being considered.
**
** 	The second parameter (int signed_bit) is the location of the signed bit,
** 	zero if there is none. In the case of an unsigned value this parameter is
**	also zero.
**
**	The third parameter (int length) is the number of bytes the number is.
**	One can get this number by doing passing a sizeof(<type>).
**		char      = 1
**		short     = 2
**		int       = 4
**		long long = 8
**
**	The fourth paramter (char *symbols) is the charset / symbols that will be
**	used for the conversion.
**
**	Lastly there is the (size_t base) parameter that will be the how much of
**	symbols set will be used. This is usually the length of the fourth parameter
**	but in case you are using a union of the symbols it may be different.
*/

long long	signed_mask(int signed_bit)
{
	long long	mask;
	int			i;

	i = 0;
	mask = 0;
	while (i < signed_bit)
	{
		mask = mask << 8;
		mask = mask | 0b11111111;
		i++;
	}
	return (mask);
}

char		*ft_ntoa(unsigned long long value, int signed_bit, int length, char *symbols, size_t base)
{
	int			neg_sign;
	int			i;
	char		*result;
	long long	mask;

	result = malloc(sizeof(*result) * 21);
	ft_bzero(result, 21);
	neg_sign = 0;
	if (signed_bit != 0)
	{
		mask = signed_mask(length);
		neg_sign = (value & (1ULL << (signed_bit * 8 - 1))) ? 1 : 0;
		if (neg_sign)
		{
			value = value * -1 - 1;
			value = value & mask;
			value = value + 1;
		}
	}
	i = 0;
	while (value > 0)
	{
		result[i] = symbols[value % base];
		value = value / base;
		i++;
	}
	if (neg_sign)
		result[i] = '-';
	return (ft_strrev(result));
}