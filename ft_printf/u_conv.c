/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:56:19 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:54:18 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_and_un(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_putunbr(var->u, var);
	}
	else if (var->secondchar == 2)
	{
		if (!var->checkstar)
			print_zero(s, var);
		ft_putunbr(var->u, var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->secondchar == 3)
	{
		ft_putunbr(var->u, var);
		if (var->thirdchar == 1 || var->thirdchar == 2)
			print_sp(s, var);
	}
	else
		ft_putunbr(var->u, var);
}

static void	min_and_un(const char **s, t_struct *var)
{
	if (var->secondchar == 1 || (var->secondchar == 2 && var->thirdchar == 1))
	{
		ft_putunbr(var->u, var);
		print_sp(s, var);
	}
	else if ((var->secondchar == 2 && var->thirdchar == 2) ||
			(var->secondchar == 3 && var->thirdchar == 0))
	{
		ft_putunbr(var->u, var);
		print_sp(s, var);
	}
	else
		ft_putunbr(var->u, var);
}

static void	exec_min_star_in_prec_un(const char **s, t_struct *var)
{
	if (var->secondchar == 3)
	{
		if (var->thirdchar == 1)
		{
			ft_putunbr(var->u, var);
			print_sp(s, var);
		}
	}
	else if (var->secondchar == 4)
	{
		if (var->u == 0 && var->star == 0)
			return ;
		if (var->checkstar)
			ft_putunbr(var->u, var);
		else if (!(var->checkstar))
		{
			print_zero(s, var);
			ft_putunbr(var->u, var);
		}
	}
}

static void	prec_and_un(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_putunbr(var->u, var);
	}
	else if (var->secondchar == 2)
	{
		if (var->thirdchar == 1)
		{
			print_zero(s, var);
			ft_putunbr(var->u, var);
		}
		else if (!var->thirdchar)
			if (var->u)
				ft_putunbr(var->u, var);
	}
	else if (var->secondchar == 3)
		exec_min_star_in_prec_un(s, var);
	else if (var->secondchar == 4)
		exec_min_star_in_prec_un(s, var);
	else if (var->u)
		ft_putunbr(var->u, var);
	else
		return ;
}

void		u_conv(const char **s, va_list ap, t_struct *var)
{
	var->u = (unsigned int)va_arg(ap, unsigned int);
	if (var->firstchar == 1)
	{
		print_sp(s, var);
		ft_putunbr(var->u, var);
	}
	else if (var->firstchar == 2)
		zero_and_un(s, var);
	else if (var->firstchar == 3)
		min_and_un(s, var);
	else if (var->firstchar == 4 && var->thirdchar == 0)
	{
		if (!var->checkstar)
			print_sp(s, var);
		ft_putunbr(var->u, var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->firstchar == 5)
		prec_and_un(s, var);
	else
		ft_putunbr(var->u, var);
}
