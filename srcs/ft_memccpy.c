/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:34:58 by sohechai          #+#    #+#             */
/*   Updated: 2021/05/20 16:48:28 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	size_t			j;
	unsigned char	*sdest;
	unsigned char	*ssrc;

	i = 0;
	j = 0;
	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
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
