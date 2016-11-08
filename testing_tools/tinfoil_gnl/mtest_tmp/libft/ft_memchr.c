/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 21:44:12 by dtse              #+#    #+#             */
/*   Updated: 2016/09/23 21:44:13 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*s_tmp;

	s_tmp = (char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)*s_tmp == (unsigned char)c || *s_tmp == c)
			return ((unsigned char *)s_tmp);
		s_tmp++;
		i++;
	}
	return (NULL);
}
