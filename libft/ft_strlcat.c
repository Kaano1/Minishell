/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:36:30 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/08 18:34:11 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(dst);
	i = 0;
	if (len >= size)
		return (size + ft_strlen(src));
	while (src[i] != 0 && len < size - 1)
	{
		dst[len] = src[i];
		i++;
		len++;
	}
	dst[len] = 0;
	return (ft_strlen(dst) + ft_strlen(&src[i]));
}
