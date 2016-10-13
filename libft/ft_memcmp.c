/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 22:10:03 by dtse              #+#    #+#             */
/*   Updated: 2016/09/23 22:10:04 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	count;

	count = 0;
	while (count < n)
	{
		if (((unsigned char*)s1)[count] != ((unsigned char*)s2)[count])
			return (((unsigned char*)s1)[count] - ((unsigned char*)s2)[count]);
		count++;
	}
	return (0);
}
