/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/09 13:14:26 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	a;
	size_t	b;
	size_t	size;

	if (*needle == '\0')
		return ((char *)haystack);
	a = ft_strlen(haystack);
	b = ft_strlen(needle);
	if (a < b || len < b)
		return (0);
	if (a > len)
		size = len;
	else
		size = a;
	while (size-- >= b)
	{
		if (ft_memcmp(haystack, needle, b) == 0)
			return ((char *)haystack);
		haystack++;
	}
	return (0);
}
