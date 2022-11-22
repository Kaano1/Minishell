/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayumusak <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:10:44 by ayumusak          #+#    #+#             */
/*   Updated: 2022/01/16 18:46:19 by ayumusak         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_calculate(int number)
{
	size_t	i;

	i = 0;
	if (number == 0)
		i++;
	while (number)
	{
		number /= 10;
		i++;
	}
	return (i);
}

char	*ft_add(long number, size_t size, int control)
{
	char	*add;

	add = malloc(sizeof(char) * (size + 1));
	if (!add)
		return (0);
	add[size] = 0;
	while (size > 0)
	{
		add[--size] = (number % 10 + '0');
		number /= 10;
	}
	if (control == 1)
		add[0] = '-';
	return (add);
}

char	*ft_itoa(int n)
{
	long	number;
	size_t	size;
	char	*add;
	int		control;

	control = 0;
	number = n;
	size = ft_calculate(number);
	if (n < 0)
	{
		size++;
		number *= -1;
		control = 1;
	}
	add = ft_add(number, size, control);
	return (add);
}
