/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:48:17 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 23:18:13 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_and_p(const char **s, t_struct *var)
{
	ft_putstr("0x", var);
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_dectohex(var->p, 'x', 1, var);
	}
	else if (var->secondchar == 2)
	{
		if (var->checkstar)
			print_sp(s, var);
		ft_dectohex(var->p, 'x', 1, var);
		if (!var->checkstar)
			print_zero(s, var);
	}
	else if (var->secondchar == 3)
	{
		ft_dectohex(var->p, 'x', 1, var);
		if (var->thirdchar == 1 || var->thirdchar == 2)
			print_sp(s, var);
	}
	else
		ft_dectohex(var->p, 'x', 1, var);
}

static void	min_and_p(const char **s, t_struct *var)
{
	ft_putstr("0x", var);
	if ((var->secondchar == 1 || (var->secondchar == 2 && var->thirdchar == 1)))
	{
		ft_dectohex(var->p, 'x', 1, var);
		print_sp(s, var);
	}
	else if ((var->secondchar == 2 && var->thirdchar == 2) ||
			(var->secondchar == 3 && var->thirdchar == 0))
	{
		ft_dectohex(var->p, 'x', 1, var);
		print_sp(s, var);
	}
	else
		ft_dectohex(var->p, 'x', 1, var);
}

static void	star_and_p(const char **s, t_struct *var)
{
	if (!var->checkstar)
		print_sp(s, var);
	ft_putstr("0x", var);
	ft_dectohex(var->p, 'x', 1, var);
	if (var->checkstar)
		print_sp(s, var);
}

void		p_conv(const char **s, va_list ap, t_struct *var)
{
	var->p = (long long)va_arg(ap, void *);
	if (var->firstchar == 1)
	{
		print_sp(s, var);
		ft_putstr("0x", var);
		ft_dectohex(var->p, 'x', 1, var);
	}
	else if (var->firstchar == 2)
		zero_and_p(s, var);
	else if (var->firstchar == 3)
		min_and_p(s, var);
	else if (var->firstchar == 4 && var->thirdchar == 0)
		star_and_p(s, var);
	else if (var->firstchar == 5)
		prec_and_p(s, var);
	else
	{
		ft_putstr("0x", var);
		ft_dectohex(var->p, 'x', 1, var);
	}
}
