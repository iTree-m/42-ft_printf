/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 00:56:23 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 21:49:53 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	convs(const char **s, va_list ap, t_struct *var)
{
	if ((**s == 'd' || **s == 'i') && !var->precision)
		d_conv(s, ap, var);
	else if (**s == 'c' && !var->precision)
		c_conv(s, ap, var);
	else if (**s == 's' && !var->precision)
		s_conv(s, ap, var);
	else if (**s == 'x' && !var->precision)
		x_conv(s, ap, var);
	else if (**s == 'X' && !var->precision)
		xx_conv(s, ap, var);
	else if (**s == 'u' && !var->precision)
		u_conv(s, ap, var);
	else if (**s == 'p' && !var->precision)
		p_conv(s, ap, var);
	else if (**s == '%' && !var->precision)
		per_conv(s, var);
	else if (var->precision)
		execdot(s, ap, var);
}
