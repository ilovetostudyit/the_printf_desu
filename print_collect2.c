/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_collector.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <ehaggon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 14:53:25 by ehaggon          #+#    #+#             */
/*   Updated: 2019/09/16 14:04:43 by ehaggon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

int	collect_size(t_argum *p)
{
	if (p->size)
		return (0);
	if (*p->str == 'h' && *(p->str + 1) != 'h')
		return (p->size |= _S_H);
	if (*p->str == 'h' && *(p->str++) == 'h')
		return (p->size |= _S_HH);
	if (*p->str == 'l' && *(p->str + 1) != 'l')
		return (p->size |= _S_L);
	if (*p->str == 'l' && *(p->str++) == 'l')
		return (p->size |= _S_LL);
	if (*p->str == 'L')
		return (p->size |= _S_LF);
	if (*p->str == 'z')
		return (p->size |= _S_Z);
	if (*p->str == 'j')
		return (p->size |= _S_J);
	if (*p->str == 't')
		return (p->size |= _S_T);
	return (0);
}

int	collect_width(t_argum *p)
{
	if (ft_isdigit(*p->str))
	{
		p->width = ft_atoi(p->str);
		while (ft_isdigit(*p->str))
			p->str++;
		p->str--;
		return (1);
	}
	else if (*p->str == '*')
	{
		p->width = va_arg(p->ap, int);
		(p->width < 0) && (p->flag |= _F_MINUS);
		p->width = (p->width < 0) ? -p->width : p->width;
		return (1);
	}
	return (0);
}

int	collect_pcn(t_argum *p)
{
	(*p->str == '.') && (p->flag |= _F_PCN);
	(*p->str == '.') && p->str++;
	if (ft_isdigit(*p->str))
	{
		p->pcn = ft_atoi(p->str);
		while (ft_isdigit(*p->str))
			p->str++;
		p->str--;
		return (1);
	}
	else if (*p->str == '*')
		return (p->pcn = va_arg(p->ap, int));
	return (0);
}

int	collect_type(t_argum *p)
{
	char *ref;

	if (p->type || !*p->str)
		return (0);
	if (!(ref = ft_strchr(_VALID_TYPES, *p->str)))
		return (0);
	else
		return (p->type = (ptrdiff_t)(ref - _VALID_TYPES) + 1);
	return (0);
}
