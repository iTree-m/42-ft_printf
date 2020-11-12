/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:31:02 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:35:11 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_and_per(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_putchar('%', var);
	}
	else if (var->secondchar == 2)
	{
		if (!var->checkstar)
			print_zero(s, var);
		ft_putchar('%', var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->secondchar == 3)
	{
		ft_putchar('%', var);
		if (var->thirdchar == 1 || var->thirdchar == 2)
			print_sp(s, var);
	}
	else
		ft_putchar('%', var);
}

static void	min_and_per(const char **s, t_struct *var)
{
	if (var->secondchar == 1 || (var->secondchar == 2 && var->thirdchar == 1))
	{
		ft_putchar('%', var);
		print_sp(s, var);
	}
	else if ((var->secondchar == 2 && var->thirdchar == 2) ||
			(var->secondchar == 3 && var->thirdchar == 0))
	{
		ft_putchar('%', var);
		print_sp(s, var);
	}
	else
		ft_putchar('%', var);
}

static void	prec_and_per(const char **s, t_struct *var)
{
	if (var->secondchar == 1)
		ft_putchar('%', var);
	else if (var->secondchar == 2)
	{
		if (var->thirdchar == 1)
			ft_putchar('%', var);
		else if (!var->thirdchar)
			ft_putchar('%', var);
	}
	else if (var->secondchar == 3 && var->thirdchar == 1)
	{
		ft_putchar('%', var);
		print_sp(s, var);
	}
	else if (var->secondchar == 4)
		ft_putchar('%', var);
	else
		ft_putchar('%', var);
}

void		per_conv(const char **s, t_struct *var)
{
	if (var->firstchar == 1)
	{
		print_sp(s, var);
		ft_putchar('%', var);
	}
	else if (var->firstchar == 2)
		zero_and_per(s, var);
	else if (var->firstchar == 3)
		min_and_per(s, var);
	else if (var->firstchar == 4 && var->thirdchar == 0)
	{
		if (!var->checkstar)
			print_sp(s, var);
		ft_putchar('%', var);
		if (var->checkstar)
			print_sp(s, var);
	}
	else if (var->firstchar == 5)
		prec_and_per(s, var);
	else
		ft_putchar('%', var);
}
