/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 16:20:37 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:57:37 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_and_hexa(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_dectohex(var->x, 'x', 1, var);
	}
	else if (var->secondchar == 2)
	{
		if (!var->checkstar)
			print_zero(s, var);
		ft_dectohex(var->x, 'x', 1, var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->secondchar == 3)
	{
		ft_dectohex(var->x, 'x', 1, var);
		if (var->thirdchar == 1 || var->thirdchar == 2)
			print_sp(s, var);
	}
	else
		ft_dectohex(var->x, 'x', 1, var);
}

static void	min_and_hexa(const char **s, t_struct *var)
{
	if (var->secondchar == 1 || (var->secondchar == 2 && var->thirdchar == 1))
	{
		ft_dectohex(var->x, 'x', 1, var);
		print_sp(s, var);
	}
	else if ((var->secondchar == 2 && var->thirdchar == 2) ||
			(var->secondchar == 3 && var->thirdchar == 0))
	{
		ft_dectohex(var->x, 'x', 1, var);
		print_sp(s, var);
	}
	else
		ft_dectohex(var->x, 'x', 1, var);
}

static void	exec_min_star_in_prec_x(const char **s, t_struct *var)
{
	if (var->secondchar == 3 && var->thirdchar == 1)
	{
		ft_dectohex(var->x, 'x', 1, var);
		print_sp(s, var);
	}
	else if (var->secondchar == 4)
	{
		if (var->x == 0 && var->star == 0)
			return ;
		if (!var->checkstar)
		{
			print_zero(s, var);
			ft_dectohex(var->x, 'x', 1, var);
		}
		else if (var->checkstar)
			ft_dectohex(var->x, 'x', 1, var);
	}
}

static void	prec_and_hexa(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_dectohex(var->x, 'x', 1, var);
	}
	else if (var->secondchar == 2)
	{
		if (var->thirdchar == 1)
		{
			print_zero(s, var);
			ft_dectohex(var->x, 'x', 1, var);
		}
		else if (!var->thirdchar)
			if (var->x)
				ft_dectohex(var->x, 'x', 1, var);
	}
	else if (var->secondchar == 3 && var->thirdchar == 1)
		exec_min_star_in_prec_x(s, var);
	else if (var->secondchar == 4)
		exec_min_star_in_prec_x(s, var);
	else if (var->x)
		ft_dectohex(var->x, 'x', 1, var);
}

void		x_conv(const char **s, va_list ap, t_struct *var)
{
	var->x = (int)va_arg(ap, int);
	if (var->firstchar == 1)
	{
		print_sp(s, var);
		ft_dectohex(var->x, 'x', 1, var);
	}
	else if (var->firstchar == 2)
		zero_and_hexa(s, var);
	else if (var->firstchar == 3)
		min_and_hexa(s, var);
	else if (var->firstchar == 4 && var->thirdchar == 0)
	{
		if (!var->checkstar)
			print_sp(s, var);
		ft_dectohex(var->x, 'x', 1, var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->firstchar == 5)
		prec_and_hexa(s, var);
	else
		ft_dectohex(var->x, 'x', 1, var);
}
