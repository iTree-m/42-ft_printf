/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichejra <ichejra@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 20:39:10 by ichejra           #+#    #+#             */
/*   Updated: 2020/01/20 14:06:30 by ichejra          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct		s_struct
{
	int				upper_x;
	int				x;
	long			d;
	unsigned int	u;
	long long		p;
	int				n;
	int				k;
	int				c;
	int				j;
	char			*s;
	char			ch;
	int				sp;
	int				dot;
	int				flag;
	int				star;
	int				star2;
	int				zeros;
	int				minus;
	int				n_a_dot;
	int				precision;
	int				checkstar;
	int				firstchar;
	int				thirdchar;
	int				checkstar2;
	int				secondchar;
}					t_struct;

void				c_conv(const char **s, va_list ap, t_struct *var);
void				check_flag(const char **str, t_struct *var, va_list ap);
void				convs(const char **s, va_list ap, t_struct *var);
void				d_conv(const char **s, va_list ap, t_struct *var);
void				execdot(const char **str, va_list ap, t_struct *var);
void				f_dig(const char **str, t_struct *var, va_list ap);
void				f_dot(const char **str, t_struct *var, va_list ap);
void				f_min(const char **str, t_struct *var, va_list ap);
void				f_star(const char **str, t_struct *var, va_list ap);
void				f_zero(const char **str, t_struct *var, va_list ap);
int					ft_atoi(const char *str);
int					ft_dectohex(long long n, char type, int opt, t_struct *var);
int					ft_isdigit(int c);
int					ft_printf(const char *str, ...);
void				ft_putchar(char c, t_struct *var);
void				ft_putnbr(long nb, t_struct *var);
void				ft_putstr(char const *s, t_struct *var);
void				ft_putstr_n(const char *s, int len, t_struct *var);
void				ft_putunbr(long nb, t_struct *var);
int					ft_strlen(const char *s);
int					len(const char **s, t_struct *var);
int					nbr(int n);
void				prec_and_p(const char **s, t_struct *var);
void				p_conv(const char **s, va_list ap, t_struct *var);
void				per_conv(const char **s, t_struct *var);
void				print_sp_when_dot_star(const char **s, t_struct *var);
void				print_sp(const char **s, t_struct *var);
void				print_zero_when_dot_star(const char **s, t_struct *var);
void				print_zero(const char **s, t_struct *var);
void				s_conv(const char **s, va_list ap, t_struct *var);
void				s_precision(t_struct *var);
void				d_precision(const char **s, t_struct *var);
void				u_precision(const char **s, t_struct *var);
void				c_precision(const char **s, t_struct *var);
void				per_precision(const char **s, t_struct *var);
void				p_precision(const char **s, t_struct *var);
void				x_precision(const char **s, t_struct *var);
void				upper_x_precision(const char **s, t_struct *var);
void				u_conv(const char **s, va_list ap, t_struct *var);
int					unbr(unsigned int n);
void				when_dot(const char **str, t_struct *var, va_list ap);
void				when_min_zero(const char **str, t_struct *var, va_list ap);
void				x_conv(const char **s, va_list ap, t_struct *var);
void				xx_conv(const char **s, va_list ap, t_struct *var);
void				zero_when_n(const char **s, t_struct *var);

#endif
