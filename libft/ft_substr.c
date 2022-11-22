/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 06:21:03 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/16 18:48:10 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*b;
	size_t	i;
	size_t	size;

	size = ft_strlen(s);
	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (size < len)
		len = size;
	b = (char *)malloc(sizeof(char) * (len + 1));
	if (!b)
		return (0);
	i = 0;
	while (len)
	{
		b[i] = s[start + i];
		i++;
		len--;
	}
	b[i] = 0;
	return (b);
}
