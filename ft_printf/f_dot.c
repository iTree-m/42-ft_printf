/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 00:57:52 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:07:04 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	when_dot_zero(const char **str, t_struct *var)
{
	var->secondchar = 2;
	while (**str == '0')
		(*str)++;
	if (ft_isdigit(**str) && **str != '0')
	{
		var->thirdchar = 1;
		var->n = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
}

static void	when_dot_minus(const char **str, t_struct *var)
{
	var->secondchar = 3;
	(*str)++;
	if (ft_isdigit(**str) && **str != '0')
	{
		var->thirdchar = 1;
		var->n = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	if (**str == '0')
	{
		while (**str == '0')
			(*str)++;
		if (ft_isdigit(**str))
		{
			var->thirdchar = 2;
			var->n = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
}

static void	when_dot_star(const char **str, t_struct *var, va_list ap)
{
	var->secondchar = 4;
	var->star = (int)va_arg(ap, int);
	if (var->star < 0)
	{
		var->checkstar = 1;
		var->star *= -1;
	}
	(*str)++;
}

void		f_dot(const char **str, t_struct *var, va_list ap)
{
	var->dot = 1;
	(*str)++;
	if (ft_isdigit(**str) && **str != '0')
	{
		var->secondchar = 1;
		var->n = ft_atoi(*str);
		while (ft_isdigit(**str))
			(*str)++;
	}
	else if (**str == '0')
		when_dot_zero(str, var);
	else if (**str == '-')
		when_dot_minus(str, var);
	else if (**str == '*')
		when_dot_star(str, var, ap);
}
