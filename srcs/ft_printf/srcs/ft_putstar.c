/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:43:44 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:23:28 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_starpercent(t_printf *st, const char *fmt)
{
	if (fmt[st->j] == '%')
	{
		if (st->length_star >= 1)
		{
			st->length_field = st->length_star - 1;
			ft_putspaces(st);
			ft_putchar('%', st);
		}
		if (st->length_star < 0)
		{
			st->length_star *= -1;
			if (st->length_star > 1)
			{
				st->length_field = st->length_star - 1;
				ft_putchar('%', st);
				ft_putspaces(st);
			}
			else
				ft_putchar('%', st);
		}
	}
}

void	ft_starx(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'X' || fmt[st->j] == 'x')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_star >= (int)ft_strlen(st->strx))
		{
			st->length_field = st->length_star - ft_strlen(st->strx);
			ft_putspaces(st);
			ft_putstr(st->strx, st);
		}
		if (st->length_star < (int)ft_strlen(st->strx) && st->length_star >= 0)
			ft_putstr(st->strx, st);
		if (st->length_star < 0)
		{
			st->length_star *= -1;
			if (st->length_star > (int)ft_strlen(st->strx))
			{
				st->length_field = st->length_star - ft_strlen(st->strx);
				ft_putstr(st->strx, st);
				ft_putspaces(st);
			}
			else
				ft_putstr(st->strx, st);
		}
		free(st->strx);
	}
}

void	ft_staru(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'u')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_star >= ft_strlen_int_u(st->u))
		{
			st->length_field = st->length_star - ft_strlen_int_u(st->u);
			ft_putspaces(st);
			ft_putnbrforu(st->u, st);
		}
		if (st->length_star < ft_strlen_int_u(st->u) && st->length_star >= 0)
			ft_putnbrforu(st->u, st);
		if (st->length_star < 0)
		{
			st->length_star *= -1;
			if (st->length_star > ft_strlen_int_u(st->u))
			{
				st->length_field = st->length_star - ft_strlen_int_u(st->u);
				ft_putnbrforu(st->u, st);
				ft_putspaces(st);
			}
			else
				ft_putnbrforu(st->u, st);
		}
	}
}

void	ft_stard(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'd' || fmt[st->j] == 'i')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen_int(st->d);
		if (st->d < 0)
			st->len += 1;
		if (st->length_star > 0)
		{
			st->length_field = st->length_star - st->len;
			if (st->length_field > 0)
				ft_putspaces(st);
			ft_putnbr(st->d, st);
		}
		if (st->length_star <= 0)
		{
			st->length_star *= -1;
			st->length_field = st->length_star - st->len;
			ft_putnbr(st->d, st);
			if (st->length_field > 0)
				ft_putspaces(st);
		}
	}
}

void	ft_starc(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'c')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_star > 1)
		{
			st->length_field = st->length_star - 1;
			ft_putspaces(st);
			ft_putchar(st->c, st);
		}
		else if (st->length_star == 1)
			ft_putchar(st->c, st);
		else if (st->length_star < 0)
		{
			st->length_star *= -1;
			if (st->length_star > 1)
			{
				st->length_field = st->length_star - 1;
				ft_putchar(st->c, st);
				ft_putspaces(st);
			}
			else
				ft_putchar(st->c, st);
		}
	}
}
