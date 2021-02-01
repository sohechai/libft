/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:34:58 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/01 20:46:35 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	i = 0;
	j = 0;
	sdest = (unsigned char*)dest;
	ssrc = (unsigned char*)src;
	if (src == NULL && dest == NULL)
		return (0);
	while (n != 0)
	{
		*sdest = *ssrc;
		if (*ssrc == (unsigned char)c)
			return (sdest + 1);
		sdest++;
		ssrc++;
		n--;
	}
	return (NULL);
}
