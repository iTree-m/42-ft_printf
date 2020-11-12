/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   len.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 13:50:28 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 23:18:01 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	len(const char **s, t_struct *var)
{
	if (**s == 'd' || **s == 'i')
		return (nbr(var->d));
	else if (**s == 'x')
		return (ft_dectohex(var->x, 'x', 0, var));
	else if (**s == 'X')
		return (ft_dectohex(var->upper_x, 'X', 0, var));
	else if (**s == 'p')
		return (ft_dectohex(var->p, 'x', 0, var) + 2);
	else if (**s == 's')
		return (ft_strlen(var->s));
	else if (**s == 'c')
		return (1);
	else if (**s == 'u')
		return (unbr(var->u));
	else if (**s == '%')
		return (1);
	return (0);
}
