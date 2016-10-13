/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 14:32:14 by dtse              #+#    #+#             */
/*   Updated: 2016/09/26 14:32:36 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = f(s[i]);
	}
	return (str);
}
