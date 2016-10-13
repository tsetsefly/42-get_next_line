/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 11:51:45 by dtse              #+#    #+#             */
/*   Updated: 2016/09/23 11:51:45 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_tmp;
	const char		*src_tmp;

	dst_tmp = (unsigned char *)dst;
	src_tmp = (const char*)src;
	i = 0;
	while (i < n)
	{
		if (*src_tmp == c)
		{
			*dst_tmp = c;
			return (dst_tmp + 1);
		}
		*dst_tmp++ = *src_tmp++;
		i++;
	}
	return (0);
}
