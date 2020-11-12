/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_min_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 18:59:59 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:08:47 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	when_min_zero_dig(const char **str, t_struct *var, va_list ap)
{
	var->thirdchar = 1;
	var->n = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}

static void	when_min_zero_star(const char **str, t_struct *var, va_list ap)
{
	var->thirdchar = 2;
	var->star = (int)va_arg(ap, int);
	if (var->star < 0)
	{
		var->checkstar = 1;
		var->star *= -1;
	}
	(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}

void		when_min_zero(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 2;
	while (**str == '0' || **str == '-')
		(*str)++;
	if (ft_isdigit(**str))
		when_min_zero_dig(str, var, ap);
	else if (**str == '*')
		when_min_zero_star(str, var, ap);
	else if (**str == '.')
		when_dot(str, var, ap);
}
