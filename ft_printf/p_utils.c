/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 13:41:11 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:32:43 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_in_prec_p(const char **s, t_struct *var)
{
	if (var->thirdchar == 1)
	{
		print_zero(s, var);
		ft_dectohex(var->p, 'x', 1, var);
	}
	else if (!var->thirdchar)
	{
		if (var->p)
			ft_dectohex(var->p, 'x', 1, var);
		else
			return ;
	}
}

static void	star_in_prec_p(const char **s, t_struct *var)
{
	if (!var->p && var->star == 0)
		return ;
	if (var->checkstar)
		ft_dectohex(var->p, 'x', 1, var);
	else if (!var->checkstar)
	{
		print_zero(s, var);
		ft_dectohex(var->p, 'x', 1, var);
	}
}

void		prec_and_p(const char **s, t_struct *var)
{
	ft_putstr("0x", var);
	if (var->secondchar == 1)
	{
		print_zero(s, var);
		ft_dectohex(var->p, 'x', 1, var);
	}
	else if (var->secondchar == 2)
		zero_in_prec_p(s, var);
	else if (var->secondchar == 3 && var->thirdchar == 1)
	{
		ft_dectohex(var->p, 'x', 1, var);
		print_sp(s, var);
	}
	else if (var->secondchar == 4)
		star_in_prec_p(s, var);
	else if (var->p)
		ft_dectohex(var->p, 'x', 1, var);
	else
		return ;
}
