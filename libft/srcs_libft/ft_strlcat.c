/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 12:34:01 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		i;
	size_t	srclen;
	size_t	dstlen;

	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (dstlen >= size)
		return (size + srclen);
	i = (int)size;
	while (*dst && i >= 0)
	{
		dst++;
		i--;
	}
	while (*src && i-- > 1)
		*dst++ = *src++;
	if (i == 1)
		*dst++ = '\0';
	while (*dst)
		*dst++ = '\0';
	return (dstlen + srclen);
}
