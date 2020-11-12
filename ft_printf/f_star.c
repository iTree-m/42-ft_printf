/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_star.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 00:58:33 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 20:31:35 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		f_star(const char **str, t_struct *var, va_list ap)
{
	(*str)++;
	var->star = (int)va_arg(ap, int);
	if (var->star < 0)
	{
		var->checkstar = 1;
		var->minus = 1;
		var->star *= -1;
	}
	if (**str == '.')
		when_dot(str, var, ap);
}
