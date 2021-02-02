/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sofiahechaichi <sofiahechaichi@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:00:04 by sohechai          #+#    #+#             */
/*   Updated: 2021/02/02 11:22:08 by sofiahechai      ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int					ft_sizenumber(long long n, char *base)
{
	int			cmpt;
	long long	result;

	cmpt = 0;
	result = n;
	if (n < 0)
	{
		cmpt++;
		result *= -1;
	}
	while (result >= (int)ft_strlen(base))
	{
		result = result / ft_strlen(base);
		cmpt++;
	}
	if (result < (int)ft_strlen(base))
		cmpt++;
	return (cmpt);
}

unsigned long		ft_sizenumberp(unsigned long n, char *base)
{
	unsigned long		cmpt;
	unsigned long		result;

	cmpt = 0;
	result = n;
	while (result >= ft_strlenp(base))
	{
		result = result / ft_strlenp(base);
		cmpt++;
	}
	if (result < ft_strlenp(base))
		cmpt++;
	return (cmpt);
}

char				*ft_itoabasep(unsigned long n, char *base)
{
	int		cmpt;
	int		set_base;
	char	*nb_str;

	cmpt = ft_sizenumberp(n, base);
	set_base = ft_strlen(base);
	if (!(nb_str = malloc(sizeof(char) * ft_sizenumberp(n, base) + 1)))
		return (NULL);
	nb_str[cmpt--] = '\0';
	if (n == 0)
	{
		nb_str[0] = base[0];
		return (nb_str);
	}
	while (cmpt >= 0)
	{
		nb_str[cmpt--] = base[n % set_base];
		n /= set_base;
	}
	return (nb_str);
}

char				*ft_itoabase(long long n, char *base)
{
	int		cmpt;
	int		set_base;
	char	*nb_str;

	cmpt = ft_sizenumber(n, base);
	set_base = ft_strlen(base);
	if (n < 0)
	{
		cmpt = 8;
		n = 4294967296 + n;
	}
	if (!(nb_str = malloc(sizeof(char) * ft_sizenumber(n, base) + 1)))
		return (NULL);
	nb_str[cmpt--] = '\0';
	if (n == 0)
	{
		nb_str[0] = base[0];
		return (nb_str);
	}
	while (cmpt >= 0)
	{
		nb_str[cmpt--] = base[n % set_base];
		n /= set_base;
	}
	return (nb_str);
}
