/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <ayumusak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 17:20:22 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/16 18:46:56 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long			i;
	long long int	result;

	i = 1;
	result = 0;
	while (*nptr == ' ' || *nptr == '\n' || *nptr == '\r' || *nptr == '\t'
		|| *nptr == '\v' || *nptr == '\f')
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			i = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		result = ((result * 10) + (*nptr - '0') * i);
		nptr++;
		if (result > 2147483647)
			return (-1);
		else if (result < -2147483648)
			return (0);
	}
	return (result);
}
