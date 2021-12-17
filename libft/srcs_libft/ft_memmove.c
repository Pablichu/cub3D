/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 11:51:18 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/26 15:07:20 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

void	*aux(char **s1, char **s2, size_t n, int type)
{
	size_t	a;

	if (type)
	{
		a = 0;
		while (a < n)
		{
			*s1[a] = *s2[a];
			a++;
		}
	}
	else
	{
		a = n;
		while (a > 0)
		{
			a--;
			*s1[a] = *s2[a];
		}
	}
	return (s1);
}

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*s1;
	char	*s2;

	s1 = (char *)str1;
	s2 = (char *)str2;
	if (!s1 && !s2)
		return (0);
	if (s2 > s1)
		aux(&s1, &s2, n, 1);
	else
		aux(&s1, &s2, n, 0);
	return (str1);
}
