/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 18:14:07 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/01 20:46:35 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sizenumber(int n)
{
	int		cmpt;
	int		result;

	cmpt = 0;
	result = n;
	if (n < 0)
	{
		cmpt++;
		result *= -1;
	}
	while (result >= 10)
	{
		result = result / 10;
		cmpt++;
	}
	if (result < 10)
		cmpt++;
	return (cmpt);
}

char		*ft_itoa(int n)
{
	int			cmpt;
	char		*nb_str;

	cmpt = ft_sizenumber(n);
	if (!(nb_str = malloc(sizeof(char) * ft_sizenumber(n) + 1)))
		return (NULL);
	nb_str[cmpt--] = '\0';
	// if (n == -2147483648)
	// 	return (ft_strdup("-2147483648"));
	if (n == 0)
	{
		nb_str[0] = '0';
		return (nb_str);
	}
	if (n < 0)
	{
		nb_str[0] = '-';
		n *= -1;
	}
	while (cmpt >= 0 && n > 0)
	{
		nb_str[cmpt--] = n % 10 + '0';
		n = n / 10;
	}
	return (nb_str);
}
