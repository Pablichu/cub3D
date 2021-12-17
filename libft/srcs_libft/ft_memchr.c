/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 12:08:07 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (a < n)
	{
		if (*((unsigned char *)str + a) == (unsigned char)c)
			return ((unsigned char *)str + a);
		a++;
	}
	return (0);
}
