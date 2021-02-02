/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writedotnext.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:04:51 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:22:59 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_dots(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 's')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_dot < (int)ft_strlen(st->s))
			ft_putlenstr(st->s, st->length_dot, st);
		if (st->length_dot < 0 || st->length_dot >= (int)ft_strlen(st->s))
			ft_putstr(st->s, st);
		ft_free_s(st);
	}
}

void	ft_dotp(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'p')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen(st->strp);
		if (st->length_dot > st->len)
		{
			st->i = st->length_dot - st->len;
			while (st->i--)
				ft_putchar('0', st);
			ft_putstr(st->strp, st);
		}
		if (st->length_dot >= 0 && st->p == 0)
			ft_putstr("0x", st);
		else if (st->length_dot < st->len && st->length_dot >= 0)
			ft_putstr(st->strp, st);
		else if (st->length_dot < 0)
			ft_putstr(st->strp, st);
		free(st->strp);
	}
}

void	ft_dotc(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'c')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putchar(st->c, st);
	}
}

void	ft_putdot(t_printf *st, const char *fmt, va_list ap)
{
	ft_dots(st, fmt, ap);
	ft_dotc(st, fmt, ap);
	ft_dotp(st, fmt, ap);
	ft_dotd(st, fmt, ap);
	ft_dotu(st, fmt, ap);
	ft_dotx(st, fmt, ap);
	ft_dotpercent(st, fmt);
}
