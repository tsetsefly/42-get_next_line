/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:24:10 by dtse              #+#    #+#             */
/*   Updated: 2016/09/29 16:25:11 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*tmpstr;
	char	tmpchar1;

	tmpstr = str;
	i = ft_strlen(str) - 1;
	len = (i / 2) + 1;
	j = 0;
	while (len--)
	{
		tmpchar1 = str[i];
		str[i] = str[j];
		str[j] = tmpchar1;
		i--;
		j++;
	}
	str = tmpstr;
	return (str);
}
