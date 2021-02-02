/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:42:07 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:17:05 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int		ft_isnbwithoutzero(const char *fmt, t_printf *st)
{
	if (fmt[st->j] > '0' && fmt[st->j] <= '9')
		return (1);
	return (0);
}

int		ft_isnb(const char *fmt, t_printf *st)
{
	if (fmt[st->j] >= '0' && fmt[st->j] <= '9')
		return (1);
	return (0);
}

int		ft_isflagplus1(const char *fmt, t_printf *st)
{
	if (fmt[st->j + 1] == 'c' || fmt[st->j + 1] == 's' || fmt[st->j + 1] == 'p'
		|| fmt[st->j + 1] == 'd' || fmt[st->j + 1] == 'i'
		|| fmt[st->j + 1] == 'u' || fmt[st->j + 1] == 'x'
		|| fmt[st->j + 1] == 'X')
		return (1);
	return (0);
}

int		ft_isflag(const char *fmt, t_printf *st)
{
	if (fmt[st->j] == 'c' || fmt[st->j] == 's' || fmt[st->j] == 'p' ||
		fmt[st->j] == 'd' || fmt[st->j] == 'i' || fmt[st->j] == 'u' ||
		fmt[st->j] == 'x' || fmt[st->j] == 'X' || fmt[st->j] == '%')
		return (1);
	return (0);
}
