/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dtse <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 22:57:19 by dtse              #+#    #+#             */
/*   Updated: 2016/11/03 22:57:22 by dtse             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_realloc(char *old_str, size_t len)
{
	char	*new_str;

	new_str = (char*)malloc(sizeof(char) * len);
	ft_bzero(new_str, len);
	ft_memcpy(new_str, old_str, ft_strlen(old_str) + 1);
	free(old_str);
	return (new_str);
}
