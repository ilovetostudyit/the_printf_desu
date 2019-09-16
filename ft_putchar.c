/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehaggon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:44:54 by ehaggon          #+#    #+#             */
/*   Updated: 2019/06/03 11:42:10 by ehaggon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
** Outputs the character c to the standard output.
*/

#include "libft.h"

ssize_t	ft_putchar(char c)
{
	return (ft_putchar_fd(c, 1));
}
