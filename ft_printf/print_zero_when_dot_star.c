/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_zero_when_dot_star.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 13:23:57 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 13:06:38 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	check_arg(const char **s, t_struct *var)
{
	if (**s == 'x')
		var->k = var->zeros - ft_dectohex(var->x, 'x', 0, var);
	else if (**s == 'X')
		var->k = var->zeros - ft_dectohex(var->upper_x, 'X', 0, var);
	else if (**s == 'p')
	{
		if (!var->checkstar)
			var->k = var->zeros - ft_dectohex(var->p, 'x', 0, var);
		else
			var->k = var->zeros - (ft_dectohex(var->p, 'x', 0, var) + 2);
	}
	else if (**s == 'd' || **s == 'i')
		var->k = var->zeros - nbr(var->d);
	else if (**s == 's')
		var->k = var->zeros - ft_strlen(var->s);
	else if (**s == 'c')
		var->k = var->zeros - 1;
	else if (**s == 'u')
		var->k = var->zeros - unbr(var->u);
	else if (**s == '%')
		var->k = var->zeros - 1;
}

void		print_zero_when_dot_star(const char **s, t_struct *var)
{
	int j;

	j = 0;
	if (var->zeros)
		check_arg(s, var);
	while (j++ < var->k && var->k > 0)
		ft_putchar('0', var);
}
