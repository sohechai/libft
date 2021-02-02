/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 14:58:37 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_zerodot(const char *fmt, t_printf *st, va_list ap)
{
	if (fmt[st->j] == '.')
	{
		st->j++;
		st->length_field = st->length_dot;
		st->length_dot = ft_atoiwithst(fmt, st);
		if (fmt[st->j] == '*')
		{
			st->length_dot = (va_arg(ap, int));
			st->j++;
		}
		if (fmt[st->j] == '%')
		{
			st->length_dot = st->length_field;
			if (st->length_dot > 1)
			{
				st->i = st->length_dot - 1;
				putzeros(st);
				ft_putchar('%', st);
			}
			else
				ft_putchar('%', st);
		}
		else
			ft_putzerodot(fmt, st, ap);
	}
}

void	ft_zero(const char *fmt, t_printf *st, va_list ap)
{
	if (fmt[st->j] == '0')
	{
		st->length_dot = ft_atoiwithst(fmt, st);
		if (fmt[st->j] == '*')
		{
			st->length_dot = va_arg(ap, int);
			st->j++;
		}
		if (ft_isflag(fmt, st) == 1)
		{
			if (st->length_dot >= 0)
				ft_putzero(fmt, st, ap);
			else
			{
				st->length_star = st->length_dot;
				ft_putstar(st, fmt, ap);
			}
		}
		ft_zerodot(fmt, st, ap);
	}
}
