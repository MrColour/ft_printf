/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmira <kmira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/07 18:09:42 by kmira             #+#    #+#             */
/*   Updated: 2019/07/13 12:46:00 by kmira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** HEADERS
*/

# include <stdarg.h>
# include <string.h>
# include <unistd.h>

# include "libft.h"
# include "ft_printf_structs.h"
# include "color.h"

# include "debug.h"

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** MACROS
*/

# define FORMAT 0
# define OUTPUT 1

# define N_SPECIFIERS 12

# define NULL_TERM 0

# ifndef EXIT
#  define EXIT(error_msg) ft_puterror(error_msg)
# endif

int			ft_printf(const char *format, ...);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: args_tools.c
** Handles things dealing with va_args, like fetching size arguement
*/

int			get_arguement_size(int specifier, int length);
void		set_specifier_handler(t_polymorphous_functions *function, const char *specifier);
t_string	do_function(t_polymorphous_functions *function, int arguement_size, t_format *format, va_list args);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** FILE: conversion_parser.c
** Deals with extracting and parsing the modifiers and specifier into struct t_format
** from a given string.
*/

t_format	extract_format(const char *format_string, size_t *index);

/*
** -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-  -_---_-_-
** DIRECTORY: conversions
** Directory that has the files to handle the different conversions.
*/

t_string	c_handler(t_format *format, int c);
t_string	s_handler(t_format *format, char *string);
t_string	p_handler(t_format *format, void *pointer);
t_string	d_handler(t_format *format, long long value);
t_string	u_handler(t_format *format, unsigned long long value);
t_string	x_handler(t_format *format, unsigned long long value);
t_string	f_handler(t_format *format, long double value);
t_string	perc_handler(t_format *format, ...);

#endif
