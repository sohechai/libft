/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simpleflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 16:42:28 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_flagu(t_printf *st, va_list ap, const char *fmt)
{
	if (fmt[st->j] == 'u')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putnbrforu(st->u, st);
	}
}

void	ft_flagx(t_printf *st, va_list ap, const char *fmt)
{
	if (fmt[st->j] == 'x' || fmt[st->j] == 'X')
	{
		ft_stock_arg(fmt, st, ap);
		ft_putstr(st->strx, st);
		free(st->strx);
	}
}

void	ft_printsimpleflag(t_printf *st, va_list ap, const char *fmt)
{
	if (ft_isflag(fmt, st) == 1)
	{
		ft_flagc(st, ap, fmt);
		ft_flags(st, ap, fmt);
		ft_flagp(st, ap, fmt);
		ft_flagd(st, ap, fmt);
		ft_flagu(st, ap, fmt);
		ft_flagx(st, ap, fmt);
		ft_flagpercent(st, fmt);
	}
}
