/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_min.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 13:37:49 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/17 17:40:07 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	when_min_dig(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 1;
	var->n = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}

static void	when_min_star(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 3;
	var->star = (int)va_arg(ap, int);
	if (var->star < 0)
	{
		var->checkstar = 1;
		var->star *= -1;
	}
	(*str)++;
	if (**str != '.')
		var->thirdchar = 0;
	else if (**str == '.')
		when_dot(str, var, ap);
}

void		f_min(const char **str, t_struct *var, va_list ap)
{
	var->minus = 1;
	while (**str == '-')
		(*str)++;
	if (ft_isdigit(**str) && **str != '0')
		when_min_dig(str, var, ap);
	else if (**str == '0')
		when_min_zero(str, var, ap);
	else if (**str == '*')
		when_min_star(str, var, ap);
	else if (**str == '.')
		when_dot(str, var, ap);
}
