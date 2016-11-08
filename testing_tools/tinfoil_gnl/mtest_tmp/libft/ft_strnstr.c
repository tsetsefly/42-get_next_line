/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 21:50:36 by dtse              #+#    #+#             */
/*   Updated: 2016/09/21 21:50:38 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	needle_search;

	if (!*little)
		return ((char *)big);
	i = 0;
	while (big[i] && len > 0)
	{
		j = 0;
		needle_search = len;
		while (big[i + j] == little[j] && needle_search > 0)
		{
			if (little[j + 1] == '\0')
				return ((char *)&big[i]);
			j++;
			needle_search--;
		}
		i++;
		len--;
	}
	return (NULL);
}
