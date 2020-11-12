/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_precision.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:20:21 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 22:15:38 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	min(int m, int n)
{
	if (m < n)
		return (m);
	else
		return (n);
}

static void	sp_and_not_zero(t_struct *var)
{
	int j;

	j = 0;
	if (!var->minus)
	{
		if (var->checkstar2)
		{
			while (j++ < (int)(var->sp - ft_strlen(var->s)))
				ft_putchar(' ', var);
			ft_putstr(var->s, var);
		}
		else
		{
			if (var->firstchar == 2)
				while (j++ < var->sp)
					ft_putchar('0', var);
			else
				while (j++ < var->sp)
					ft_putchar(' ', var);
		}
	}
	else
		while (j++ < var->sp)
			ft_putchar(' ', var);
}

static void	sp_and_zero_not_min(t_struct *var)
{
	if (var->sp >= var->zeros && !var->checkstar2)
	{
		if (var->firstchar == 2)
			while (var->j++ < var->sp - min(ft_strlen(var->s), var->zeros))
				ft_putchar('0', var);
		else
			while (var->j++ < var->sp - min(ft_strlen(var->s), var->zeros))
				ft_putchar(' ', var);
	}
	else
	{
		if (var->firstchar == 2)
			while (var->j++ < var->sp - ft_strlen(var->s))
				ft_putchar('0', var);
		else
			while (var->j++ < var->sp - ft_strlen(var->s))
				ft_putchar(' ', var);
	}
	if (var->checkstar2)
	{
		ft_putstr(var->s, var);
		return ;
	}
	ft_putstr_n(var->s, var->zeros, var);
}

static void	sp_and_zero(t_struct *var)
{
	int j;

	j = 0;
	if (!var->minus)
		sp_and_zero_not_min(var);
	if (var->minus)
	{
		if (!var->checkstar2)
			ft_putstr_n(var->s, var->zeros, var);
		if (var->checkstar2)
			ft_putstr(var->s, var);
		if (var->sp > var->zeros && !var->checkstar2)
			while (j++ < (int)(var->sp - min(ft_strlen(var->s), var->zeros)))
				ft_putchar(' ', var);
		else
			while (j++ < (int)(var->sp - ft_strlen(var->s)))
				ft_putchar(' ', var);
	}
}

void		s_precision(t_struct *var)
{
	if (var->s == NULL)
		var->s = "(null)";
	if (var->sp && !var->zeros)
		sp_and_not_zero(var);
	if (!var->sp && var->zeros && !var->checkstar2)
		ft_putstr_n(var->s, var->zeros, var);
	if (!var->sp && var->zeros && var->checkstar2)
		ft_putstr(var->s, var);
	if (var->sp && var->zeros)
		sp_and_zero(var);
}
