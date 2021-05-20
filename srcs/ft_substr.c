/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 13:40:21 by sohechai          #+#    #+#             */
/*   Updated: 2021/05/20 16:53:35 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*dest;

	i = 0;
	size = ft_strlen(s);
	dest = malloc(sizeof(char) * len + 1);
	if (!(dest))
		return (NULL);
	while (len != 0 && start < size)
	{
		dest[i] = s[start];
		start++;
		i++;
		len--;
	}
	dest[i] = '\0';
	return (dest);
}
