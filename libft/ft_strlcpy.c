/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 10:22:03 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/08 21:17:39 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	j;

	j = 0;
	srcsize = 0;
	if (!dstsize)
		return (ft_strlen(src));
	srcsize = ft_strlen(src);
	if (dstsize != 0)
	{
		while (j < dstsize - 1 && src[j])
		{
			((char *)dst)[j] = ((const char *)src)[j];
			j++;
		}
		dst[j] = '\0';
	}
	return (srcsize);
}
