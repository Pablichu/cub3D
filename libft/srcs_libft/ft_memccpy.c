/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:08:54 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

void	*ft_memccpy(void *dest, const void *orig, int c, size_t n)
{
	void	*p;
	size_t	a;

	p = ft_memchr(orig, c, n);
	if (p != NULL)
	{
		a = 0;
		while (a < n && ((char *)orig)[a] != 0)
		{
			((char *)dest)[a] = ((char *)orig)[a];
			if (((char *)orig)[a] == (char)c)
			{
				a++;
				return (&((char *)dest)[a]);
			}
			a++;
		}
	}
	ft_memcpy(dest, orig, n);
	return (NULL);
}
