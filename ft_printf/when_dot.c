/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   when_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 19:54:46 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 22:21:58 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		when_dot(const char **str, t_struct *var, va_list ap)
{
	var->dot = 1;
	var->precision = 1;
	if (var->star)
		var->sp = var->star;
	else if (var->n)
		var->sp = var->n;
	(*str)++;
	if (**str == '*')
	{
		var->zeros = (int)va_arg(ap, int);
		if (var->zeros < 0)
		{
			var->checkstar2 = 1;
			var->zeros = -1;
		}
	}
	else if (ft_isdigit(**str))
	{
		while (**str == '0')
			(*str)++;
		var->zeros = ft_atoi(*str);
	}
	else
		var->zeros = 0;
	(var->zeros < 0) ? var->zeros = -1 : 0;
}
