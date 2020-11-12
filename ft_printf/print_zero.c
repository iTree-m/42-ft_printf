/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:22:34 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 13:06:52 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	zero_when_star_p(t_struct *var)
{
	if (!var->checkstar)
		var->k = var->star - ft_dectohex(var->p, 'x', 0, var);
	else
		var->k = var->star - (ft_dectohex(var->p, 'x', 0, var) + 2);
}

static void	zero_when_star_di(t_struct *var)
{
	var->k = var->star - nbr(var->d);
	if (var->d < 0 && !(var->checkstar) && var->firstchar != 5)
	{
		ft_putchar('-', var);
		var->d *= -1;
	}
	else if (var->d < 0 && var->firstchar == 5)
	{
		var->k += 1;
		ft_putchar('-', var);
		var->d *= -1;
	}
}

static void	zero_when_star(const char **s, t_struct *var)
{
	if (**s == 'x')
		var->k = var->star - ft_dectohex(var->x, 'x', 0, var);
	else if (**s == 'X')
		var->k = var->star - ft_dectohex(var->upper_x, 'X', 0, var);
	else if (**s == 'p')
		zero_when_star_p(var);
	else if (**s == 'd' || **s == 'i')
		zero_when_star_di(var);
	else if (**s == 's')
		var->k = var->star - ft_strlen(var->s);
	else if (**s == 'c')
		var->k = var->star - 1;
	else if (**s == 'u')
		var->k = var->star - unbr(var->u);
	else if (**s == '%')
		var->k = var->star - 1;
}

void		print_zero(const char **s, t_struct *var)
{
	int j;

	j = 0;
	var->k = 0;
	if (var->n)
		zero_when_n(s, var);
	else if (var->star)
		zero_when_star(s, var);
	while (j++ < var->k && var->k > 0)
		ft_putchar('0', var);
}
