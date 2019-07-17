/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 17:59:46 by kmira             #+#    #+#             */
/*   Updated: 2019/07/16 15:00:53 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft/libft.h"

int		convert(const char *format, size_t *index, va_list args)
{
	t_format					formatter;
	t_polymorphous_functions	function;
	int							arguement_size;
	t_string					converted_string;

	if (format[*index] == '%')
		*index = *index + 1;

	formatter = extract_format(format, index);					//extract length is not general
	set_specifier_handler(&function, formatter.specifier);		//set_specifier_handler is not general
	arguement_size = get_arguement_size(formatter.specifier[0], formatter.length);
	converted_string = do_function(&function, arguement_size, &formatter, args);
	write(1, converted_string.output, converted_string.length);
	*index = *index + 1;
	return (converted_string.length);
}

int		ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	j;
	size_t	result;
	va_list args;

	va_start(args, format);
	i = 0;
	result = 0;
	while (format[i] != '\0')
	{
		j = 0;
		while (format[j + i] != '\0' && format[j + i] != '%')
			j++;
		write(1, &(format[i]), j);
		result = result + j;
		i = i + j;
		if (format[i] == '%')
			result += convert(format, &i, args);
	}
	va_end(args);
	return (result);
}
