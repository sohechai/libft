/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfielddot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 18:44:47 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void		ft_fielddotx(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'X' || fmt[st->j] == 'x')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen(st->strx);
		if (st->length_field > 0)
			ft_fieldisposx(st);
		else if (st->length_field <= 0)
			ft_fieldisnegx(st);
		free(st->strx);
	}
}

void		ft_fielddotu(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'u')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen_int_u(st->u);
		if (st->u >= 0 && st->length_field > 0)
			st->length_field += 1;
		if (st->length_dot == 0 && st->u == 0)
			st->len -= 1;
		if (st->length_field >= 0)
		{
			if (st->length_dot < st->len)
				st->length_field -= st->len + 1;
			else
				st->length_field -= st->length_dot + 1;
			st->i = st->length_dot - st->len;
			if (st->length_field > 0)
				ft_putspaces(st);
			if (st->length_dot > 0 && st->length_dot > st->len)
				putzeros(st);
			if (st->length_dot != 0 || st->u != 0)
				ft_putnbrforu(st->u, st);
		}
		else if (st->length_field < 0)
			ft_fieldisnegu(st);
	}
}

void		ft_fielddotpercent(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == '%')
	{
		if (st->length_field == 0)
			ft_putchar('%', st);
		else if (st->length_field > 1)
		{
			st->length_field -= 1;
			ft_putspaces(st);
			ft_putchar('%', st);
		}
		else
		{
			st->length_star = st->length_field;
			ft_putstar(st, fmt, ap);
		}
	}
}

void		ft_putfielddot(const char *fmt, t_printf *st, va_list ap)
{
	ft_fielddotpercent(st, fmt, ap);
	ft_fielddotc(st, fmt, ap);
	ft_fielddots(st, fmt, ap);
	ft_fielddotp(st, fmt, ap);
	ft_fielddotd(st, fmt, ap);
	ft_fielddotu(st, fmt, ap);
	ft_fielddotx(st, fmt, ap);
}
