/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_difminus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/16 19:20:55 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:15:53 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_minusfielddot(const char *fmt, t_printf *st, va_list ap)
{
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

void	ft_minusfield(t_printf *st, const char *fmt, va_list ap)
{
	if (ft_isnb(fmt, st) == 1)
	{
		st->length_star = ft_atoiwithst(fmt, st);
		st->length_field = st->length_star;
		if (st->length_star > 0)
			st->length_star *= -1;
		if (ft_isflag(fmt, st) == 1)
			ft_putstar(st, fmt, ap);
		ft_minusfielddot(fmt, st, ap);
	}
}

void	ft_minusstar(const char *fmt, t_printf *st, va_list ap)
{
	if (fmt[st->j] == '*')
	{
		st->length_star = va_arg(ap, int);
		st->j++;
		if (st->length_star > 0)
			st->length_star *= -1;
		if (ft_isflag(fmt, st) == 1)
			ft_putstar(st, fmt, ap);
		ft_minusfielddot(fmt, st, ap);
	}
}

void	ft_minus(const char *fmt, t_printf *st, va_list ap)
{
	if (fmt[st->j] == '-')
	{
		while (fmt[st->j] == '-')
			st->j++;
		if (ft_isflag(fmt, st) == 1)
			ft_printsimpleflag(st, ap, fmt);
		ft_minusfield(st, fmt, ap);
		ft_minusstar(fmt, st, ap);
	}
}
