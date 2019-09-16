/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 19:53:11 by ehaggon          #+#    #+#             */
/*   Updated: 2019/09/16 14:04:43 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_str_pcn(t_argum *p, char *s, int space)
{
	int		len;
	char	c;

	c = (p->flag & _F_ZERO && !(p->flag & _F_MINUS)) ? '0' : ' ';
	len = ft_strlen(s);
	if (p->flag & _F_MINUS)
	{
		while (p->pcn-- && len--)
			ft_putchar(*s++);
		put_nchar(c, space);
	}
	else if (!(p->flag & _F_MINUS))
	{
		put_nchar(c, space);
		while (p->pcn-- && len--)
			ft_putchar(*s++);
	}
}

void	print_str_(t_argum *p, char *s, int space)
{
	char c;

	c = (p->flag & _F_ZERO && !(p->flag & _F_MINUS)) ? '0' : ' ';
	(!s) && (s = "(null)");
	if (p->flag & _F_PCN)
		print_str_pcn(p, s, space);
	else
	{
		if (!(p->flag & _F_MINUS))
			put_nchar(c, space);
		ft_putstr(s);
		if (p->flag & _F_MINUS)
			put_nchar(c, space);
	}
}

char	*get_str_argv(t_argum *p)
{
	va_list		ap;
	int			tmp;
	char		*s;

	tmp = p->argv;
	va_copy(ap, p->ap);
	while (tmp--)
		s = va_arg(ap, char *);
	va_end(ap);
	return (s);
}

void	print_str(t_argum *p)
{
	int		space;
	int		len;
	char	*s;

	s = (p->argv) ? get_str_argv(p) : va_arg(p->ap, char *);
	len = (s) ? ft_strlen(s) : 6;
	space = get_nspace(p, len);
	if (!(p->flag & _F_PCN))
		p->done += (len + space);
	else if (p->flag & _F_PCN)
		p->done += (p->pcn > len) ? (len + space) : (p->pcn + space);
	if ((p->done) >= INT_MAX)
		return ;
	print_str_(p, s, space);
}
