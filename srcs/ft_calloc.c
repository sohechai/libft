/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohechai <sohechai@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 17:31:57 by sohechai          #+#    #+#             */
/*   Updated: 2021/05/20 16:38:04 by sohechai         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!(ptr))
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
