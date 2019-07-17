/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conversion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 10:55:44 by kmira             #+#    #+#             */
/*   Updated: 2019/07/17 12:04:36 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** FLAGS:
** 		VALID FLAGS: -
** 			VALID FLAGS: 1/5
** 		INVALID FLAGS: + #0
** 			INVALID FLAGS: 4/5
**
** WIDTH:
** 		Is always applicable.
**
** PRECISION:
** 		Is not applicale.
*/

t_string	c_handler(t_format *format, int c)
{
	t_string	result;

	if (format->width == 0)
		format->width = 1;
	result.output = malloc(sizeof(*result.output) * (format->width));
	ft_memset(result.output, ' ', format->width);
	if (format->flags & MINUS_FLAG)
		result.output[0] = c;
	else
		result.output[format->width - 1] = c;
	result.length = format->width;
	result.free = TRUE;
	return (result);
}
