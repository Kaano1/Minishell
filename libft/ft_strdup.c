/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 10:30:49 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/12 22:45:03 by ayumusak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*s2;
	size_t	i;
	size_t	j;

	j = 0;
	i = ft_strlen(s) + 1;
	s2 = (char *)malloc(sizeof(char) * i);
	if (!s || !s2)
		return (0);
	while (i > j)
	{
		((unsigned char *)s2)[j] = ((unsigned char *)s)[j];
		j++;
	}
	return (s2);
}
