/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 14:48:17 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:15:53 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int		ft_strlen_int(long n)
{
	int		cmpt;
	long	result;

	cmpt = 0;
	result = n;
	if (n < 0)
		result *= -1;
	while (result >= 10)
	{
		result = result / 10;
		cmpt++;
	}
	if (result < 10)
		cmpt++;
	return (cmpt);
}

int		ft_strlen_int_u(long n)
{
	int		cmpt;
	long	result;

	cmpt = 0;
	result = n;
	if (result < 0)
		result = 4294967295 - n + 1;
	while (result >= 10)
	{
		result = result / 10;
		cmpt++;
	}
	if (result < 10)
		cmpt++;
	return (cmpt);
}
