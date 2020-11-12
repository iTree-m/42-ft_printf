/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execdot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 21:18:12 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 23:21:11 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	get_conv(const char **str)
{
	while (**str != 'd' && **str != 'i' && **str != 'c' && **str != 'u' &&
			**str != 'x' && **str != 'X' && **str != 'p' && **str != 's'
			&& **str != '%')
		(*str)++;
}

static void	know_conv_arg(const char **str, va_list ap, t_struct *var)
{
	if (**str == 'd' || **str == 'i')
		var->d = (int)va_arg(ap, int);
	else if (**str == 'c')
		var->ch = (int)va_arg(ap, int);
	else if (**str == 'u')
		var->u = (unsigned int)va_arg(ap, unsigned int);
	else if (**str == 'x')
		var->x = (int)va_arg(ap, int);
	else if (**str == 'X')
		var->upper_x = (int)va_arg(ap, int);
	else if (**str == 'p')
		var->p = (long long)va_arg(ap, void *);
	else if (**str == 's')
		var->s = (char *)va_arg(ap, char *);
}

void		execdot(const char **str, va_list ap, t_struct *var)
{
	get_conv(str);
	know_conv_arg(str, ap, var);
	if (**str == 'd' || **str == 'i')
		d_precision(str, var);
	else if (**str == 's')
		s_precision(var);
	else if (**str == 'c')
		c_precision(str, var);
	else if (**str == '%')
		per_precision(str, var);
	else if (**str == 'u')
		u_precision(str, var);
	else if (**str == 'x')
		x_precision(str, var);
	else if (**str == 'X')
		upper_x_precision(str, var);
	else if (**str == 'p')
		p_precision(str, var);
}
