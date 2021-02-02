/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfielddotnext.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 13:17:03 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:24:25 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_fielddots(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 's')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_field >= 0)
		{
			if (st->length_dot >= ft_strlen(st->s) || st->length_dot < 0)
				st->length_field -= ft_strlen(st->s);
			else if (st->length_dot < ft_strlen(st->s) && st->length_dot > 0)
				st->length_field -= st->length_dot;
			if (st->length_field > 0)
				ft_putspaces(st);
			if (st->length_dot >= ft_strlen(st->s) || st->length_dot < 0)
				ft_putstr(st->s, st);
			else if (st->length_dot < ft_strlen(st->s) && st->length_dot > 0)
				ft_putlenstr(st->s, st->length_dot, st);
		}
		else if (st->length_field < 0)
			ft_fieldisnegs(st);
		ft_free_s(st);
	}
}

void	ft_fielddotp(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'p')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen(st->strp);
		if (st->length_field < 0 && st->length_field * -1 > st->len &&
			st->length_field * -1 > st->len + (st->length_dot - st->len))
			ft_fieldisnegp(st);
		else if (st->length_field == 0 && st->p == 0)
			ft_putstr("0x", st);
		else if (st->length_field >= st->len || st->length_dot >= st->len)
			ft_fieldcompletep(st);
		else
			ft_putstr(st->strp, st);
		free(st->strp);
	}
}

void	ft_fielddotx2(t_printf *st)
{
	if (st->length_field > st->len && st->length_dot < st->len)
	{
		st->length_field -= st->len;
		ft_putspaces(st);
	}
	else if (st->length_dot >= st->len)
	{
		st->i = st->length_dot - ft_strlen(st->strx);
		if (st->length_field >= ft_strlen(st->strx) &&
			st->length_field >= st->length_dot)
		{
			st->length_field -= ft_strlen(st->strx) + st->i;
			ft_putspaces(st);
		}
		putzeros(st);
	}
}

void	ft_fieldisnegs(t_printf *st)
{
	st->length_field *= -1;
	if (st->length_dot >= ft_strlen(st->s) || st->length_dot < 0)
		ft_putstr(st->s, st);
	else if (st->length_dot < ft_strlen(st->s) && st->length_dot > 0)
		ft_putlenstr(st->s, st->length_dot, st);
	if (st->length_dot >= ft_strlen(st->s) || st->length_dot < 0)
		st->length_field -= ft_strlen(st->s);
	else if (st->length_dot < ft_strlen(st->s) && st->length_dot > 0)
		st->length_field -= st->length_dot;
	if (st->length_field > 0)
		ft_putspaces(st);
}
