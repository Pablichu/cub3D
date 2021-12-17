/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 11:55:42 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

static int	nlen(int n)
{
	if (n == 0)
		return (1);
	return (1 + nlen(n / 10));
}

static char	*inscad(char *cad, int n, int len)
{
	unsigned int	aux;

	aux = 0;
	if (n == 0)
		*cad = 48;
	else if (n < 0)
	{
		*cad = '-';
		aux = n * (-1);
	}
	else
		aux = n;
	cad[len + 1] = '\0';
	while (aux != 0)
	{
		cad[len] = aux % 10 + 48;
		aux = aux / 10;
		len--;
	}
	return (cad);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*cad;

	if (n > 0)
		len = nlen(n) - 1;
	else
		len = nlen(n);
	cad = (char *)malloc(sizeof(char) * len + 1);
	if (!cad)
		return (NULL);
	return (inscad(cad, n, len - 1));
}
