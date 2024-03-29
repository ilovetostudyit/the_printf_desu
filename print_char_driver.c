/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_driver.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 10:58:28 by ehaggon          #+#    #+#             */
/*   Updated: 2019/09/16 14:04:43 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_(t_argum *p, char c)
{
	char	d;

	d = (p->flag & _F_ZERO && !(p->flag & _F_MINUS)) ? '0' : ' ';
	if (!(p->flag & _F_MINUS))
		put_nchar(d, p->width - 1);
	ft_putchar(c);
	if (p->flag & _F_MINUS)
		put_nchar(d, p->width - 1);
}

int		get_char_argv(t_argum *p)
{
	va_list		ap;
	int			tmp;
	int			c;

	tmp = p->argv;
	va_copy(ap, p->ap);
	while (tmp-- > 0)
		c = va_arg(ap, int);
	va_end(ap);
	return (c);
}

void	print_char(t_argum *p)
{
	char		c;

	c = (p->argv) ? get_char_argv(p) : va_arg(p->ap, long int);
	p->done += (p->width) ? (p->width) : 1;
	if ((p->done) >= INT_MAX)
		return ;
	print_char_(p, c);
}

void	print_mod(t_argum *p)
{
	p->done += (p->width) ? (p->width) : 1;
	print_char_(p, '%');
}
