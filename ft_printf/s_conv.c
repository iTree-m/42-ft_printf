/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:55:44 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/20 14:13:36 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_and_str(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_putstr(var->s, var);
	}
	else if (var->secondchar == 2)
	{
		if (!var->checkstar)
			print_zero(s, var);
		ft_putstr(var->s, var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->secondchar == 3)
	{
		ft_putstr(var->s, var);
		if (var->thirdchar == 1 || var->thirdchar == 2)
			print_sp(s, var);
	}
	else
		ft_putstr(var->s, var);
}

static void	min_and_str(const char **s, t_struct *var)
{
	if (var->secondchar == 1 || (var->secondchar == 2 && var->thirdchar == 1))
	{
		ft_putstr(var->s, var);
		print_sp(s, var);
	}
	else if ((var->secondchar == 2 && var->thirdchar == 2) ||
			(var->secondchar == 3 && var->thirdchar == 0))
	{
		ft_putstr(var->s, var);
		print_sp(s, var);
	}
	else
		ft_putstr(var->s, var);
}

static void	prec_and_str(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
		ft_putstr_n(var->s, var->n, var);
	else if (var->secondchar == 2)
	{
		if (var->thirdchar == 1)
			ft_putstr_n(var->s, var->n, var);
		else if (!var->thirdchar)
			return ;
	}
	else if (var->secondchar == 3)
	{
		if (var->thirdchar == 1)
		{
			ft_putstr(var->s, var);
			print_sp(s, var);
		}
	}
	else if (var->secondchar == 4)
	{
		if (var->s && var->star == 0)
			return ;
		(var->checkstar) ? ft_putstr(var->s, var)
		: ft_putstr_n(var->s, var->star, var);
	}
}

void		s_conv(const char **s, va_list ap, t_struct *var)
{
	var->s = (char *)va_arg(ap, char *);
	if (var->s == NULL)
		var->s = "(null)";
	if (var->firstchar == 1)
	{
		print_sp(s, var);
		ft_putstr(var->s, var);
	}
	else if (var->firstchar == 2)
		zero_and_str(s, var);
	else if (var->firstchar == 3)
		min_and_str(s, var);
	else if (var->firstchar == 4 && var->thirdchar == 0)
	{
		if (var->checkstar)
			ft_putstr(var->s, var);
		print_sp(s, var);
		if (!var->checkstar)
			ft_putstr(var->s, var);
	}
	else if (var->firstchar == 5)
		prec_and_str(s, var);
	else
		ft_putstr(var->s, var);
}
