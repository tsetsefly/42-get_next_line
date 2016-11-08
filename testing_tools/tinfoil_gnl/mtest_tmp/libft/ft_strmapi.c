/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:51:15 by dtse              #+#    #+#             */
/*   Updated: 2016/09/26 15:51:56 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = f(i, s[i]);
	}
	return (str);
}
