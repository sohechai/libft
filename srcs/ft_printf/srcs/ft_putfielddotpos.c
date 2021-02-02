/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfielddotpos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:00:02 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void		ft_fieldisposx(t_printf *st)
{
	if (st->x >= 0)
		st->length_field += 1;
	if (st->length_dot == 0 && st->x == 0)
		st->len -= 1;
	if (st->x < 0)
		st->length_field += 1;
	if (st->length_dot < st->len)
		st->length_field -= st->len + 1;
	else
		st->length_field -= st->length_dot + 1;
	st->i = st->length_dot - st->len;
	if (st->length_field > 0)
		ft_putspaces(st);
	if (st->length_dot > 0 && st->length_dot > st->len)
		putzeros(st);
	if (st->length_dot != 0 || st->x != 0)
		ft_putstr(st->strx, st);
}

void		ft_fieldisnegp(t_printf *st)
{
	st->length_field *= -1;
	st->length_field += 1;
	if (st->length_dot == 0 && st->p == 0)
		st->len -= 1;
	if (st->length_dot < st->len)
		st->length_field -= st->len + 1;
	else
		st->length_field -= st->length_dot + 1;
	st->i = st->length_dot - st->len;
	if (st->length_dot > 0 && st->length_dot > st->len)
		putzeros(st);
	if (st->p == 0)
		ft_putstr("0x", st);
	else
		ft_putstr(st->strp, st);
	if (st->length_field > 0)
		ft_putspaces(st);
}

void		ft_fieldcompletep(t_printf *st)
{
	if (st->length_field > st->len && st->length_dot < st->len)
	{
		st->length_field -= st->len;
		ft_putspaces(st);
	}
	else if (st->length_dot >= st->len)
		ft_fielddotp2(st);
	if (st->p == 0)
		ft_putstr(" 0x", st);
	else
		ft_putstr(st->strp, st);
}

void		ft_fielddotp2(t_printf *st)
{
	if (st->length_field > st->len && st->length_dot < st->len)
	{
		st->length_field -= st->len;
		ft_putspaces(st);
	}
	else if (st->length_dot >= st->len)
	{
		st->i = st->length_dot - st->len;
		if (st->length_field >= st->len &&
			st->length_field >= st->length_dot)
		{
			st->length_field -= st->len + st->i;
			ft_putspaces(st);
		}
		putzeros(st);
	}
}

void		ft_fielddotc(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'c')
		ft_starc(st, fmt, ap);
}
