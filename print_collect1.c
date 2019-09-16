/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_collect1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:39:34 by ehaggon           #+#    #+#             */
/*   Updated: 2019/09/16 17:40:35 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	collect_argv(t_argum *p)
{
	const char	*s;

	s = p->str;
	while (ft_isdigit(*s))
		s++;
	if (*s != '$')
		return (0);
	else
		p->argv = ft_atoi(p->str);
	while (ft_isdigit(*p->str))
		p->str++;
	return (1);
}

int	collect_flag(t_argum *p)
{
	if (*p->str == '-')
		return (p->flag |= _F_MINUS);
	if (*p->str == '+')
		return (p->flag |= _F_PLUS);
	if (*p->str == ' ')
		return (p->flag |= _F_SPACE);
	if (*p->str == '0')
		return (p->flag |= _F_ZERO);
	if (*p->str == '#')
		return (p->flag |= _F_HASH);
	return (0);
}