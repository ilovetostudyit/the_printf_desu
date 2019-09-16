/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_pointer_driver.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 16:19:54 by ehaggon          #+#    #+#             */
/*   Updated: 2019/09/16 14:04:43 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_vp_case1(t_argum *p, uintmax_t n)
{
	p->done += ft_putstr("0x");
	(!n && !p->pcn && p->flag & _F_PCN) ? 0 : print_unbr_base_lo(n, 16);
}

void	print_vp_case2(t_argum *p, uintmax_t n, int space)
{
	char c;

	c = (p->flag & _F_ZERO && !(p->flag & _F_MINUS || p->flag & _F_PCN)) ?
		'0' : ' ';
	(c == ' ' && !(p->flag & _F_MINUS)) && put_nchar(c, space);
	p->done += ft_putstr("0x");
	(c == '0') && put_nchar(c, space);
	(!n && !p->pcn && p->flag & _F_PCN) ? 0 : print_unbr_base_lo(n, 16);
	(c == ' ' && (p->flag & _F_MINUS)) && put_nchar(c, space);
}

void	print_vp_case3(t_argum *p, uintmax_t n, int pads)
{
	p->done += ft_putstr("0x");
	put_nchar('0', pads);
	(!n && !p->pcn && p->flag & _F_PCN) ? 0 : print_unbr_base_lo(n, 16);
}

void	print_vp_case4(t_argum *p, uintmax_t n, int space, int pads)
{
	!(p->flag & _F_MINUS) && put_nchar(' ', space);
	p->done += ft_putstr("0x");
	put_nchar('0', pads);
	(!n && !p->pcn && p->flag & _F_PCN) ? 0 : print_unbr_base_lo(n, 16);
	(p->flag & _F_MINUS) && put_nchar(' ', space);
}

void	print_vp_driver(t_argum *p, uintmax_t n, int space, int pads)
{
	if (!space && !pads)
		print_vp_case1(p, n);
	else if (space && !pads)
		print_vp_case2(p, n, space);
	else if (!space && pads)
		print_vp_case3(p, n, pads);
	else if (space && pads)
		print_vp_case4(p, n, space, pads);
}
