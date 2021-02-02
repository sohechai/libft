/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzerodot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 16:58:55 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void		ft_putzerodot(const char *fmt, t_printf *st, va_list ap)
{
	ft_putzerodotd(st, fmt, ap);
	ft_putzerodotu(st, fmt, ap);
	ft_putzerodotx(st, fmt, ap);
	ft_fielddotpercent(st, fmt, ap);
	ft_fielddotc(st, fmt, ap);
	ft_fielddots(st, fmt, ap);
	ft_fielddotp(st, fmt, ap);
}

void		ft_putzeroisposd(t_printf *st)
{
	if (st->d < 0 && st->length_dot > st->len)
		st->length_field -= 1;
	if (st->d == 0 && st->length_dot == 0)
		st->length_field += 1;
	if (st->length_dot == 0 && st->d != 0)
	{
		st->i = -1;
		st->length_field -= st->len;
	}
	else if (st->length_dot >= 0)
	{
		if (st->length_dot < st->len)
			st->length_field -= st->len;
		else
			st->length_field -= st->length_dot;
		st->i = st->length_dot - st->len;
	}
	else if (st->length_dot < 0)
	{
		st->length_dot *= -1;
		st->i = st->length_field - st->len;
		st->length_field *= -1;
	}
}

void		ft_putzeroisnegd(t_printf *st)
{
	st->length_field *= -1;
	if (st->d == 0 && st->length_dot == 0)
		st->length_field += 1;
	if (st->length_dot >= st->len)
		st->length_field -= st->length_dot;
	else
		st->length_field -= st->len;
	st->i = st->length_dot - st->len;
	if (st->d < 0)
		ft_putchar('-', st);
	if (st->i > 0)
		putzeros(st);
	if (st->length_dot != 0 || st->d != 0)
		ft_putnbrforzero(st->d, st);
	if (st->length_field > 0)
		ft_putspaces(st);
}

void		ft_putzerodotd(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'd' || fmt[st->j] == 'i')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen_int(st->d);
		if (st->d < 0 && st->length_dot <= st->len && st->d != 0)
			st->len += 1;
		if (st->length_field >= 0)
		{
			ft_putzeroisposd(st);
			if (st->length_field > 0)
				ft_putspaces(st);
			if (st->d < 0)
				ft_putchar('-', st);
			if (st->i > 0)
				putzeros(st);
			if (st->length_dot != 0 || st->d != 0)
				ft_putnbrforzero(st->d, st);
		}
		else if (st->length_field < 0)
			ft_putzeroisnegd(st);
	}
}

void		ft_putzeroisposu(t_printf *st)
{
	if (st->length_dot == 0 && st->u != 0)
	{
		st->i = -1;
		st->length_field -= st->len;
	}
	else if (st->length_dot >= 0)
	{
		if (st->u == 0 || st->length_dot >= st->len)
			st->length_field -= st->length_dot;
		else if (st->length_dot > st->len)
			st->length_field -= st->length_dot + st->len;
		else
			st->length_field -= st->len;
		st->i = st->length_dot - st->len;
	}
	else if (st->length_dot < 0)
	{
		st->length_dot *= -1;
		st->i = st->length_field - st->len;
		st->length_field *= -1;
	}
}
