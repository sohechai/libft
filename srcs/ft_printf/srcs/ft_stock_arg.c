/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:45:36 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_stock_diux(const char *fmt, t_printf *st, va_list ap)
{
	if (fmt[st->j] == 'u')
		st->u = va_arg(ap, long);
	else if (fmt[st->j] == 'x')
	{
		st->x = va_arg(ap, int);
		st->strx = ft_itoabase(st->x, "0123456789abcdef");
	}
	else if (fmt[st->j] == 'X')
	{
		st->x = va_arg(ap, int);
		st->strx = ft_itoabase(st->x, "0123456789ABCDEF");
	}
}

void	ft_stock_arg(const char *fmt, t_printf *st, va_list ap)
{
	if (fmt[st->j] == 'c')
		st->c = va_arg(ap, int);
	else if (fmt[st->j] == 's')
	{
		st->s = va_arg(ap, char *);
		if (st->s == NULL)
			st->s = ft_strdup("(null)");
	}
	else if (fmt[st->j] == 'p')
	{
		st->p = va_arg(ap, unsigned long);
		st->tmp = ft_itoabasep(st->p, "0123456789abcdef");
		st->strp = ft_strjoin("0x", st->tmp);
		free(st->tmp);
	}
	else if (fmt[st->j] == 'd' || fmt[st->j] == 'i')
		st->d = va_arg(ap, int);
	ft_stock_diux(fmt, st, ap);
}
