/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:08:19 by sohechai          #+#    #+#             */
/*   Updated: 2021/05/20 16:49:38 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (c == s[i])
			return ((char *)s + i);
		s++;
	}
	if (c == '\0' && s[i] == '\0')
		return ((char *)s);
	return (NULL);
}
