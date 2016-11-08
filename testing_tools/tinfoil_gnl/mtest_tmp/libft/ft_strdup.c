/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 11:10:35 by dtse              #+#    #+#             */
/*   Updated: 2016/09/21 11:10:37 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *str)
{
	size_t	i;
	char	*cpy;

	i = ft_strlen(str) + 1;
	if (!(cpy = (char *)malloc((sizeof(char) * i))))
		return (NULL);
	ft_strcpy(cpy, str);
	return (cpy);
}
