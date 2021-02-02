/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putzeronext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:09:56 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_putzeropercent(t_printf *st, const char *fmt)
{
	if (fmt[st->j] == '%')
	{
		if (st->length_dot > 1)
		{
			st->i = st->length_dot - 1;
			putzeros(st);
			ft_putchar('%', st);
		}
		else
			ft_putchar('%', st);
	}
}

void	ft_putzerod(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'd' || fmt[st->j] == 'i')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen_int(st->d);
		if (st->d < 0)
			st->len += 1;
		if (st->length_dot >= st->len)
		{
			st->i = st->length_dot - st->len;
			if (st->d < 0)
				ft_putchar('-', st);
			putzeros(st);
			ft_putnbrforzero(st->d, st);
		}
		else if (st->length_dot < st->len && st->length_dot >= 0)
			ft_putnbr(st->d, st);
	}
}
