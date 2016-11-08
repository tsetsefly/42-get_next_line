/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delimwc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:36:00 by dtse              #+#    #+#             */
/*   Updated: 2016/09/29 16:36:02 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_delimwc(char *str, char c)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i])
			words++;
		while (str[i] != c && str[i])
			i++;
	}
	return (words);
}
