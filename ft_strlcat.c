/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:30:39 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/01 20:46:35 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	lendest;
	size_t	i;
	size_t	j;

	lendest = ft_strlen(dest);
	i = 0;
	j = 0;
	if (lendest > size)
		return (ft_strlen(src) + size);
	while (src[i] && size - lendest > 1)
	{
		dest[lendest + i] = src[j];
		i++;
		j++;
		size--;
	}
	dest[lendest + j] = '\0';
	return (ft_strlen(src) + lendest);
}
