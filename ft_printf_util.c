/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:54:58 by ehaggon          #+#    #+#             */
/*   Updated: 2019/09/16 14:06:06 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_argum(t_argum *p)
{
	p->argv = 0;
	p->flag = 0;
	p->pcn = 0;
	p->size = 0;
	p->type = 0;
	p->width = 0;
	p->done = 0;
	p->str = NULL;
}

void	reset_collector(t_argum *p)
{
	p->argv = 0;
	p->flag = 0;
	p->pcn = 0;
	p->size = 0;
	p->type = 0;
	p->width = 0;
}

int		put_nchar(char c, int n)
{
	if (n <= 0)
		return (0);
	while (n--)
		ft_putchar(c);
	return (1);
}

int		get_nspace(t_argum *p, int len)
{
	int space;

	space = 0;
	if (p->width <= p->pcn && p->width >= len)
		space = (p->pcn >= len) ? (p->width - len) : 0;
	else if (p->width && !p->pcn && !(p->flag & _F_PCN))
		space = (p->width > len) ? (p->width - len) : 0;
	else if (p->width > p->pcn)
		space = (p->pcn >= len) ? (p->width - len) : (p->width - p->pcn);
	return (space);
}
