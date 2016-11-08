/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 20:49:59 by dtse              #+#    #+#             */
/*   Updated: 2016/09/23 20:50:04 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dst_tmp;
	const char	*src_tmp;

	dst_tmp = (char*)dst;
	src_tmp = (const char*)src;
	if (dst_tmp <= src_tmp)
		return (ft_memcpy(dst, src, len));
	else
	{
		dst_tmp += len;
		src_tmp += len;
		while (len--)
			*(--dst_tmp) = *(--src_tmp);
	}
	return (dst);
}
