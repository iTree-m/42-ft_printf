/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_x_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 16:31:11 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 22:06:27 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_s(const char **s, t_struct *var)
{
	int j;
	int ln;

	j = 0;
	ln = len(s, var);
	if (!var->upper_x && var->zeros == 0)
		ln -= 1;
	if (var->firstchar == 2 && var->checkstar2 == 1 && !var->minus)
		return ;
	if (var->sp <= ln)
		return ;
	while (j < var->n && ((j + ln) != var->sp))
	{
		ft_putchar(' ', var);
		j++;
	}
}

static void	print_z(const char **s, t_struct *var)
{
	int j;
	int ln;

	j = 0;
	ln = len(s, var);
	if (var->checkstar2 && var->firstchar == 2 && !var->minus)
	{
		if (var->sp <= ln)
			return ;
		while (j < var->sp && (j + ln != var->sp))
		{
			ft_putchar('0', var);
			j++;
		}
		return ;
	}
	while (j < ((int)(var->zeros - ln)))
	{
		ft_putchar('0', var);
		j++;
	}
}

static void	sp_and_zero(const char **s, t_struct *var)
{
	var->n = var->sp - var->zeros;
	if (!var->minus)
	{
		print_s(s, var);
		print_z(s, var);
		ft_dectohex(var->upper_x, 'X', 1, var);
	}
	if (var->minus)
	{
		print_z(s, var);
		ft_dectohex(var->upper_x, 'X', 1, var);
		print_s(s, var);
	}
}

static void	sp_and_not_zero(const char **s, t_struct *var)
{
	var->n = var->sp;
	if (!var->minus)
	{
		print_s(s, var);
		if (var->upper_x)
			ft_dectohex(var->upper_x, 'X', 1, var);
	}
	else if (var->minus)
	{
		if (var->upper_x)
			ft_dectohex(var->upper_x, 'X', 1, var);
		print_s(s, var);
	}
}

void		upper_x_precision(const char **s, t_struct *var)
{
	if (var->sp && var->zeros)
		sp_and_zero(s, var);
	else if (var->sp && var->zeros == 0)
		sp_and_not_zero(s, var);
	else if (!var->sp && var->zeros)
	{
		print_z(s, var);
		ft_dectohex(var->upper_x, 'X', 1, var);
	}
	else if (!var->sp && var->zeros == 0)
	{
		if (var->upper_x)
			ft_dectohex(var->upper_x, 'X', 1, var);
	}
}
