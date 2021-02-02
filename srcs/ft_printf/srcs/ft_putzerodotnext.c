/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzerodotnext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:24:57 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void		ft_putzeroisnegu(t_printf *st)
{
	st->length_field *= -1;
	if (st->u == 0 && st->length_dot == 0)
		st->length_field += 1;
	if (st->length_dot >= st->len)
		st->length_field -= st->length_dot;
	else
		st->length_field -= st->len;
	st->i = st->length_dot - st->len;
	if (st->i > 0)
		putzeros(st);
	if (st->length_dot != 0 || st->u != 0)
		ft_putnbrforu(st->u, st);
	if (st->length_field > 0)
		ft_putspaces(st);
}

void		ft_putzerodotu(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'u')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen_int_u(st->u);
		if (st->length_field >= 0)
		{
			ft_putzeroisposu(st);
			if (st->length_field > 0)
				ft_putspaces(st);
			if (st->i > 0)
				putzeros(st);
			if (st->length_dot != 0 || st->u != 0)
				ft_putnbrforu(st->u, st);
		}
		else if (st->length_field < 0)
			ft_putzeroisnegu(st);
	}
}

void		ft_putzeroisposx(t_printf *st)
{
	if (st->length_dot == 0 && st->x != 0)
	{
		st->i = -1;
		st->length_field -= st->len;
	}
	else if (st->length_dot >= 0)
	{
		if (st->length_dot == 0 && st->x == 0)
			st->length_field += 1;
		if (st->length_dot >= st->len)
			st->length_field -= st->length_dot;
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

void		ft_putzeroisnegx(t_printf *st)
{
	st->length_field *= -1;
	if (st->x == 0 && st->length_dot == 0)
		st->length_field += 1;
	if (st->length_dot >= st->len)
		st->length_field -= st->length_dot;
	else
		st->length_field -= st->len;
	st->i = st->length_dot - st->len;
	if (st->i > 0)
		putzeros(st);
	if (st->length_dot != 0 || st->x != 0)
		ft_putstr(st->strx, st);
	if (st->length_field > 0)
		ft_putspaces(st);
}

void		ft_putzerodotx(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'X' || fmt[st->j] == 'x')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen(st->strx);
		if (st->length_field >= 0)
		{
			ft_putzeroisposx(st);
			if (st->length_field > 0)
				ft_putspaces(st);
			if (st->i > 0)
				putzeros(st);
			if (st->length_dot != 0 || st->x != 0)
				ft_putstr(st->strx, st);
		}
		else if (st->length_field < 0)
			ft_putzeroisnegx(st);
		free(st->strx);
	}
}
