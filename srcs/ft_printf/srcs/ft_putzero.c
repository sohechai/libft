/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:09:58 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putzerox(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'x' || fmt[st->j] == 'X')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_dot >= ft_strlen(st->strx))
		{
			st->i = st->length_dot - ft_strlen(st->strx);
			putzeros(st);
			ft_putstr(st->strx, st);
		}
		if (st->length_dot < ft_strlen(st->strx) && st->length_dot >= 0)
			ft_putstr(st->strx, st);
		if (st->length_dot < 0)
		{
			st->length_dot *= -1;
			if (st->length_dot > ft_strlen(st->strx))
			{
				st->i = st->length_dot - ft_strlen(st->strx);
				ft_putstr(st->strx, st);
				putzeros(st);
			}
			else
				ft_putstr(st->strx, st);
		}
		free(st->strx);
	}
}

void	ft_putzerou(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'u')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_dot >= ft_strlen_int_u(st->u))
		{
			st->i = st->length_dot - ft_strlen_int_u(st->u);
			while (st->i--)
				ft_putchar('0', st);
			ft_putnbrforu(st->u, st);
		}
		else if (st->length_dot < ft_strlen_int(st->u) && st->length_dot >= 0)
			ft_putnbrforu(st->u, st);
	}
}

void	ft_putzerop(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'p')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen(st->strp);
		if (st->length_dot >= st->len)
		{
			st->i = st->length_dot - st->len;
			ft_putstr(st->strp, st);
			putzeros(st);
		}
		if (st->length_dot < st->len && st->length_dot >= 0)
			ft_putstr(st->strp, st);
		if (st->length_dot < 0)
			ft_putzeropisneg(st);
		free(st->strp);
	}
}

void	ft_putzeropisneg(t_printf *st)
{
	st->length_dot *= -1;
	if (st->length_dot > st->len)
	{
		st->i = st->length_dot - st->len;
		ft_putstr(st->strp, st);
		putzeros(st);
	}
	else
		ft_putstr(st->strp, st);
}

void	ft_putzero(const char *fmt, t_printf *st, va_list ap)
{
	ft_putzerod(st, fmt, ap);
	ft_putzerou(st, fmt, ap);
	ft_putzerop(st, fmt, ap);
	ft_putzerox(st, fmt, ap);
	ft_putzeropercent(st, fmt);
}
