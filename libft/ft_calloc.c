/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:02:05 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/06 11:02:50 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t x, size_t size)
{
	void	*str;
	size_t	total;

	total = size * x;
	str = malloc(total);
	if (!str)
		return (0);
	while (total != 0)
	{
		((unsigned char *)str)[total - 1] = 0;
		total--;
	}
	return (str);
}
