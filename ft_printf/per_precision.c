/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 13:37:23 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 21:59:31 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	exec_per(const char **s, t_struct *var)
{
	int ln;
	int j;

	ln = len(s, var);
	j = 0;
	if (!var->minus)
	{
		if (var->firstchar == 2)
			while (j++ < var->sp - ln)
				ft_putchar('0', var);
		else
			while (j++ < var->sp - ln)
				ft_putchar(' ', var);
		ft_putchar('%', var);
	}
	else if (var->minus)
	{
		ft_putchar('%', var);
		while (j++ < var->sp - ln)
			ft_putchar(' ', var);
	}
}

void		per_precision(const char **s, t_struct *var)
{
	int ln;
	int j;

	ln = len(s, var);
	j = 0;
	if (var->sp && !var->zeros)
		exec_per(s, var);
	else if (var->sp && var->zeros)
		exec_per(s, var);
	else if (!var->sp && var->zeros)
		ft_putchar('%', var);
	else if (!var->sp && var->zeros == 0)
		ft_putchar('%', var);
}
