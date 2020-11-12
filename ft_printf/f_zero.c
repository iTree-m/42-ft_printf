/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 00:59:59 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/17 16:43:16 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	when_zero_dig(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 1;
	var->n = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}

static void	when_zero_star(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 2;
	var->star = (int)va_arg(ap, int);
	if (var->star < 0)
	{
		var->checkstar = 1;
		var->minus = 1;
		var->star *= -1;
	}
	(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}

static void	when_zero_minus_dig(const char **str, t_struct *var, va_list ap)
{
	var->thirdchar = 1;
	var->n = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}

static void	when_zero_minus(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 3;
	var->minus = 1;
	while (**str == '0' || **str == '-')
		(*str)++;
	if (ft_isdigit(**str))
		when_zero_minus_dig(str, var, ap);
	else if (**str == '*')
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
	else if (**str == '.')
		when_dot(str, var, ap);
}

void		f_zero(const char **str, t_struct *var, va_list ap)
{
	while (**str == '0')
		(*str)++;
	if (ft_isdigit(**str))
		when_zero_dig(str, var, ap);
	else if (**str == '*')
		when_zero_star(str, var, ap);
	else if (**str == '-')
		when_zero_minus(str, var, ap);
	else if (**str == '.')
		when_dot(str, var, ap);
}
