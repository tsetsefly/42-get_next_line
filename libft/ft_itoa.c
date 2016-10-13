/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:51:58 by dtse              #+#    #+#             */
/*   Updated: 2016/09/27 12:52:18 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	is_negzero(long *num, int *neg)
{
	if (*num < 0)
	{
		*neg = 1;
		*num *= -1;
	}
	if (*num == 0)
		*neg = 1;
}

char		*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	int		neg;
	long	num;

	neg = 0;
	i = 0;
	num = n;
	is_negzero(&num, &neg);
	if (!(str = ft_strnew(ft_numdigits(num) + neg)))
		return (NULL);
	while (num)
	{
		str[i++] = num % 10 + '0';
		num /= 10;
	}
	if (neg && n != 0)
		str[i] = '-';
	if (n == 0)
		str[0] = '0';
	return (ft_strrev(str));
}
