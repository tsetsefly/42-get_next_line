/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:34:51 by dtse              #+#    #+#             */
/*   Updated: 2016/09/21 20:34:52 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	long		dest_len;
	long		src_len;
	long		i;
	long		s;

	dest_len = ft_strlen(dest);
	src_len = ft_strlen((char*)src);
	s = size;
	i = 0;
	while ((i < s - dest_len - 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (s - dest_len - 1 > 0)
		dest[dest_len + i] = '\0';
	if (s < dest_len)
		return (s + src_len);
	else
		return (dest_len + src_len);
}
