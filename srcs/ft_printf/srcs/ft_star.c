/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_star.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:46:44 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putstar(t_printf *st, const char *fmt, va_list ap)
{
	ft_starc(st, fmt, ap);
	ft_stars(st, fmt, ap);
	ft_starp(st, fmt, ap);
	ft_stard(st, fmt, ap);
	ft_staru(st, fmt, ap);
	ft_starx(st, fmt, ap);
	ft_starpercent(st, fmt);
}

void	ft_star(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == '*')
	{
		st->length_star = va_arg(ap, int);
		st->j++;
		if (ft_isflag(fmt, st) == 1)
			ft_putstar(st, fmt, ap);
		if (fmt[st->j] == '.')
		{
			st->j++;
			st->length_field = st->length_star;
			if (ft_isnb(fmt, st) == 1)
				st->length_dot = ft_atoiwithst(fmt, st);
			else
				st->length_dot = 0;
			if (fmt[st->j] == '*')
			{
				st->length_dot = va_arg(ap, int);
				st->j++;
			}
			ft_putfielddot(fmt, st, ap);
		}
	}
}
