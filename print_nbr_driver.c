/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nbr_driver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:18:44 by ehaggon          #+#    #+#             */
/*   Updated: 2019/09/16 14:04:43 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_nbr_case1(t_argum *p, intmax_t n)
{
	process_sp_plus_flag(p, n);
	print_nbr_prototype(p, n);
}

void	print_nbr_case2(t_argum *p, intmax_t n, int space)
{
	char c;

	c = (p->flag & _F_ZERO) ? '0' : ' ';
	(p->flag & _F_PCN) && (c = ' ');
	if (p->flag & _F_PCN && !p->pcn && !n)
	{
		(!(p->flag & _F_MINUS)) && put_nchar(c, space);
		process_sp_plus_flag(p, n);
		(p->flag & _F_MINUS) && put_nchar(c, space);
		return ;
	}
	if (p->flag & _F_ZERO && !(p->flag & _F_PCN))
		process_sp_plus_flag(p, n);
	(!(p->flag & _F_MINUS)) && put_nchar(c, space);
	if (!(p->flag & _F_ZERO))
		process_sp_plus_flag(p, n);
	else if (p->flag & _F_ZERO && p->flag & _F_PCN)
		process_sp_plus_flag(p, n);
	print_nbr_prototype(p, n);
	(p->flag & _F_MINUS) && put_nchar(' ', space);
}

void	print_nbr_case3(t_argum *p, intmax_t n, int pads)
{
	process_sp_plus_flag(p, n);
	put_nchar('0', pads);
	print_nbr_prototype(p, n);
}

void	print_nbr_case4(t_argum *p, intmax_t n, int space, int pads)
{
	(!(p->flag & _F_MINUS)) && put_nchar(' ', space);
	process_sp_plus_flag(p, n);
	put_nchar('0', pads);
	print_nbr_prototype(p, n);
	(p->flag & _F_MINUS) && put_nchar(' ', space);
}

void	print_nbr_driver(t_argum *p, intmax_t n, int space, int pads)
{
	if (!space && !pads)
		print_nbr_case1(p, n);
	else if (space && !pads)
		print_nbr_case2(p, n, space);
	else if (!space && pads)
		print_nbr_case3(p, n, pads);
	else if (space && pads)
		print_nbr_case4(p, n, space, pads);
}
