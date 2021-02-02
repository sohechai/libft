/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simpleflagnext.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 21:18:16 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_flagpercent(t_printf *st, const char *fmt)
{
	if (fmt[st->j] == '%')
		ft_putchar('%', st);
}

void	ft_flagc(t_printf *st, va_list ap, const char *fmt)
{
	if (fmt[st->j] == 'c')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putchar(st->c, st);
	}
}

void	ft_flags(t_printf *st, va_list ap, const char *fmt)
{
	if (fmt[st->j] == 's')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putstr(st->s, st);
		ft_free_s(st);
	}
}

void	ft_flagp(t_printf *st, va_list ap, const char *fmt)
{
	if (fmt[st->j] == 'p')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putstr(st->strp, st);
		free(st->strp);
	}
}

void	ft_flagd(t_printf *st, va_list ap, const char *fmt)
{
	if (fmt[st->j] == 'd' || fmt[st->j] == 'i')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putnbr(st->d, st);
	}
}
