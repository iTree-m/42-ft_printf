/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dectohex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 14:05:03 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/18 23:11:12 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	ft_check_digit(long long n, char c)
{
	if (n >= 0 && n <= 9)
		return (n + '0');
	else
	{
		if (c == 'X')
			return (n + 55);
		else if (c == 'x')
			return (n + 87);
	}
	return (0);
}

int			ft_dectohex(long long n, char type, int opt, t_struct *var)
{
	unsigned int	negnum;
	static int		len;

	len = 1;
	if (n == 0)
	{
		if (opt == 1)
			ft_putchar('0', var);
		return (1);
	}
	if (n < 0)
	{
		negnum = n;
		n = negnum;
	}
	if (n / 16)
	{
		ft_dectohex(n / 16, type, opt, var);
		len++;
	}
	if (opt == 1)
		ft_putchar(ft_check_digit(n % 16, type), var);
	return (len);
}
