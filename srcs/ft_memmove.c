/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:44:16 by sohechai          #+#    #+#             */
/*   Updated: 2021/05/20 16:49:01 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*sdest;
	unsigned char	*ssrc;
	size_t			i;

	sdest = (unsigned char *)dest;
	ssrc = (unsigned char *)src;
	i = 0;
	if (src == NULL && dest == NULL)
		return (0);
	if (ssrc < sdest)
	{
		while (n--)
			sdest[n] = ssrc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (sdest);
}
