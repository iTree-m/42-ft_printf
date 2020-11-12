/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:18:27 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:37:13 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, t_struct *var)
{
	write(1, &c, 1);
	var->c++;
}

void	ft_putstr(const char *s, t_struct *var)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
		ft_putchar(s[i++], var);
}

void	ft_putstr_n(const char *s, int len, t_struct *var)
{
	int i;

	if (!s)
		return ;
	i = 0;
	while (s[i] && i < len)
		ft_putchar(s[i++], var);
}

void	ft_putnbr(long nb, t_struct *var)
{
	if (nb < 0)
	{
		ft_putchar('-', var);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10, var);
		ft_putnbr(nb % 10, var);
	}
	else
		ft_putchar(nb + '0', var);
}

void	ft_putunbr(long nb, t_struct *var)
{
	if (nb >= 10)
	{
		ft_putunbr(nb / 10, var);
		ft_putunbr(nb % 10, var);
	}
	else
		ft_putchar(nb + '0', var);
}
