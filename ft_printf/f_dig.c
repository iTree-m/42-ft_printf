/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_dig.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 01:00:58 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:06:07 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	f_dig(const char **str, t_struct *var, va_list ap)
{
	var->n = ft_atoi(*str);
	while (ft_isdigit(**str))
		(*str)++;
	if (**str == '.')
		when_dot(str, var, ap);
}
