/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:11:37 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 22:12:38 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_struct(t_struct *var)
{
	var->checkstar = 0;
	var->checkstar2 = 0;
	var->firstchar = 0;
	var->secondchar = 0;
	var->thirdchar = 0;
	var->upper_x = 0;
	var->x = 0;
	var->d = 0;
	var->u = 0;
	var->j = 0;
	var->ch = 0;
	var->s = 0;
	var->p = 0;
	var->n = 0;
	var->n_a_dot = 0;
	var->k = 0;
	var->star = 0;
	var->sp = 0;
	var->zeros = -1;
	var->dot = 0;
	var->flag = 0;
	var->precision = 0;
	var->minus = 0;
}

int			ft_printf(const char *str, ...)
{
	va_list		ap;
	t_struct	var;

	var.c = 0;
	va_start(ap, str);
	while (*str != '\0')
	{
		if (*str == '%')
		{
			init_struct(&var);
			str++;
			check_flag(&str, &var, ap);
			convs(&str, ap, &var);
		}
		else
			ft_putchar(*str, &var);
		str++;
	}
	va_end(ap);
	return (var.c);
}
