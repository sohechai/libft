/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:21:47 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:01:02 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	size_t	k;
	char	*sdest;
	char	*ssrc;

	i = 0;
	k = 0;
	sdest = (char*)dest;
	ssrc = (char*)src;
	if (src == NULL && dest == NULL)
		return (0);
	while (i < n)
	{
		sdest[k] = ssrc[i++];
		k++;
	}
	return (sdest);
}
