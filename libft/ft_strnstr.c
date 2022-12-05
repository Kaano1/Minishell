/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:29:38 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/07 18:01:10 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (*s2 == 0)
		return ((char *)s1);
	while (s1[i] != 0)
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j] != 0 && n > (j + i))
		{
			if (s2[j + 1] == 0)
				return (((char *)s1) + i);
			j++;
		}
		i++;
	}
	return (0);
}
