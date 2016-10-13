/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 21:37:30 by dtse              #+#    #+#             */
/*   Updated: 2016/09/26 21:37:44 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spacenewlinetab(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static char	*lead_trim(char *str)
{
	while (spacenewlinetab(*str))
		str++;
	return (ft_strdup(str));
}

static char	*tail_trim(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (len == 0)
		return (ft_strnew(len));
	len--;
	while (len && str[len] && spacenewlinetab(str[len]))
		len--;
	return (ft_strsub(str, 0, len + 1));
}

char		*ft_strtrim(char const *s)
{
	char	*str;

	if (!s)
		return (NULL);
	if (!(str = ft_strdup(s)))
		return (NULL);
	if (!(str = lead_trim(str)))
		return (NULL);
	if (!(str = tail_trim(str)))
		return (NULL);
	return (str);
}
