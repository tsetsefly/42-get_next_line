/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 16:55:33 by dtse              #+#    #+#             */
/*   Updated: 2016/09/26 16:56:13 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *substr;

	if (!s)
		return (NULL);
	if (!(substr = ft_strnew(len)))
		return (NULL);
	while (len--)
	{
		substr[len] = s[start + len];
	}
	return (substr);
}
