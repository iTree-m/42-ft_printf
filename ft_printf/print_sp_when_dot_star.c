/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sp_when_dot_star.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 12:48:57 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 13:05:36 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_sp_when_dot_star(const char **s, t_struct *var)
{
	int j;

	j = 0;
	if (var->sp)
	{
		if (**s == 'x')
			var->k = var->sp - ft_dectohex(var->x, 'x', 0, var);
		else if (**s == 'X')
			var->k = var->sp - ft_dectohex(var->upper_x, 'X', 0, var);
		else if (**s == 'p')
			var->k = var->sp - (ft_dectohex(var->p, 'x', 0, var) + 2);
		else if (**s == 'd' || **s == 'i')
			var->k = var->sp - nbr(var->d);
		else if (**s == 's')
			var->k = var->sp - ft_strlen(var->s);
		else if (**s == 'c')
			var->k = var->sp - 1;
		else if (**s == 'u')
			var->k = var->sp - unbr(var->u);
		else if (**s == '%')
			var->k = var->sp - 1;
	}
	while (j++ < var->k && var->k > 0)
		ft_putchar(' ', var);
}
