/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 13:03:00 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 13:05:57 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	sp_when_n(const char **s, t_struct *var)
{
	if (**s == 'x')
		var->k = var->n - ft_dectohex(var->x, 'x', 0, var);
	else if (**s == 'X')
		var->k = var->n - ft_dectohex(var->upper_x, 'X', 0, var);
	else if (**s == 'p')
		var->k = var->n - (ft_dectohex(var->p, 'x', 0, var) + 2);
	else if (**s == 'd' || **s == 'i')
		var->k = var->n - nbr(var->d);
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

static void	sp_when_star(const char **s, t_struct *var)
{
	if (**s == 'x')
		var->k = var->star - ft_dectohex(var->x, 'x', 0, var);
	else if (**s == 'X')
		var->k = var->star - ft_dectohex(var->upper_x, 'X', 0, var);
	else if (**s == 'p')
		var->k = var->star - (ft_dectohex(var->p, 'x', 0, var) + 2);
	else if (**s == 'd' || **s == 'i')
		var->k = var->star - nbr(var->d);
	else if (**s == 's')
		var->k = var->star - ft_strlen(var->s);
	else if (**s == 'c')
		var->k = var->star - 1;
	else if (**s == 'u')
		var->k = var->star - unbr(var->u);
	else if (**s == '%')
		var->k = var->star - 1;
}

void		print_sp(const char **s, t_struct *var)
{
	int j;

	j = 0;
	var->k = 0;
	if (var->n)
		sp_when_n(s, var);
	else if (var->star)
		sp_when_star(s, var);
	while (j++ < var->k && var->k > 0)
		ft_putchar(' ', var);
}
