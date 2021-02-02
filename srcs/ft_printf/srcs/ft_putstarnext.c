/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstarnext.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 15:44:08 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:23:45 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_stars(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 's')
	{
		ft_stock_arg(fmt, st, ap);
		if (st->length_star >= (int)ft_strlen(st->s))
		{
			st->length_field = st->length_star - ft_strlen(st->s);
			ft_putspaces(st);
			ft_putstr(st->s, st);
		}
		if (st->length_star < (int)ft_strlen(st->s) && st->length_star >= 0)
			ft_putstr(st->s, st);
		if (st->length_star < 0)
		{
			st->length_star *= -1;
			if (st->length_star > (int)ft_strlen(st->s))
			{
				st->length_field = st->length_star - ft_strlen(st->s);
				ft_putstr(st->s, st);
				ft_putspaces(st);
			}
			else
				ft_putstr(st->s, st);
		}
		ft_free_s(st);
	}
}

void	ft_starp(t_printf *st, const char *fmt, va_list ap)
{
	if (fmt[st->j] == 'p')
	{
		ft_stock_arg(fmt, st, ap);
		st->len = ft_strlen(st->strp);
		if (st->length_star >= st->len)
		{
			st->length_field = st->length_star - st->len;
			ft_putspaces(st);
			ft_putstr(st->strp, st);
		}
		if (st->length_star < st->len && st->length_star >= 0)
			ft_putstr(st->strp, st);
		if (st->length_star < 0)
			ft_starpisneg(st);
		free(st->strp);
	}
}

void	ft_starpisneg(t_printf *st)
{
	st->length_star *= -1;
	if (st->length_star > st->len)
	{
		st->length_field = st->length_star - st->len;
		ft_putstr(st->strp, st);
		ft_putspaces(st);
	}
	else
		ft_putstr(st->strp, st);
}

void	ft_free_s(t_printf *st)
{
	if (ft_strncmp(st->s, "(null)", 6) == 0)
		free(st->s);
}
