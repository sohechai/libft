/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_toupper.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: sohechai <sohechai@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:10:21 by sohechai     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/22 16:13:35 by sohechai    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}
