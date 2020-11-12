/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 20:16:18 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/16 12:16:40 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	int			i;
	long long	n;
	long long	sign;

	i = 0;
	n = 0;
	sign = 0;
	if (str == NULL)
		return (0);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		if (n * 10 + (long long)str[i] - '0' < n)
			return (sign == 1 ? 0 : -1);
		n = (n * 10) + ((long long)str[i++] - '0');
	}
	if (sign == 1)
		return ((int)-n);
	return ((int)n);
}

int	ft_isdigit(int c)
{
	unsigned int	c1;

	c1 = (unsigned int)c;
	if (c1 >= 48 && c1 <= 57)
		return (1);
	return (0);
}
