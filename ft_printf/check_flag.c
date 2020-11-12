/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 16:03:07 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/20 12:16:14 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_flag(const char **str, t_struct *var, va_list ap)
{
	if (ft_isdigit(**str) && **str != '0')
	{
		var->firstchar = 1;
		f_dig(str, var, ap);
	}
	else if (**str == '0')
	{
		var->firstchar = 2;
		f_zero(str, var, ap);
	}
	else if (**str == '-')
	{
		var->firstchar = 3;
		f_min(str, var, ap);
	}
	else if (**str == '*')
	{
		var->firstchar = 4;
		f_star(str, var, ap);
	}
	else if (**str == '.')
	{
		var->firstchar = 5;
		f_dot(str, var, ap);
	}
}
