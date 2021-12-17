/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 11:40:08 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	a;

	if (src || dst)
	{
		a = 0;
		while (a < n)
		{
			((unsigned char *)dst)[a] = ((unsigned char *)src)[a];
			a++;
		}
		return (dst);
	}
	return (NULL);
}
