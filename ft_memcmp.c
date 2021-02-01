/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:38:15 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/01 20:46:35 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned const char	*ss1;
	unsigned const char	*ss2;

	i = 0;
	ss1 = (unsigned const char*)s1;
	ss2 = (unsigned const char*)s2;
	if (n == 0)
		return (0);
	while (ss1[i] == ss2[i] && i < n - 1)
		i++;
	return (ss1[i] - ss2[i]);
}
