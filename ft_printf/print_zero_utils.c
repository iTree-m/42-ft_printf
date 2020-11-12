/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 15:30:53 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 13:06:26 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_when_n_p(t_struct *var)
{
	if ((var->firstchar == 5 && var->secondchar == 2 && var->thirdchar == 1) ||
			(var->firstchar == 5 && var->secondchar == 1))
		var->k = var->n - ft_dectohex(var->p, 'x', 0, var);
	else if (!var->precision)
		var->k = var->n - (ft_dectohex(var->p, 'x', 0, var) + 2);
	else if (var->precision)
		var->k = var->n - ft_dectohex(var->p, 'x', 0, var);
}

static void	zero_when_n_di(t_struct *var)
{
	var->k = var->n - nbr(var->d);
	if (var->d < 0)
	{
		if (var->firstchar == 5)
			var->k += 1;
		ft_putchar('-', var);
		var->d *= -1;
	}
}

void		zero_when_n(const char **s, t_struct *var)
{
	if (**s == 'x')
		var->k = var->n - ft_dectohex(var->x, 'x', 0, var);
	else if (**s == 'X')
		var->k = var->n - ft_dectohex(var->upper_x, 'X', 0, var);
	else if (**s == 'p')
		zero_when_n_p(var);
	else if (**s == 'd' || **s == 'i')
		zero_when_n_di(var);
	else if (**s == 'p')
		var->k = var->n - (ft_dectohex(var->p, 'x', 0, var) + 2);
	else if (**s == 's')
		var->k = var->n - ft_strlen(var->s);
	else if (**s == 'c')
		var->k = var->n - 1;
	else if (**s == 'u')
		var->k = var->n - unbr(var->u);
	else if (**s == '%')
		var->k = var->n - 1;
}
