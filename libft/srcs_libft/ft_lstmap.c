/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/01 15:43:34 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_h;
	t_list	*new_n;
	t_list	*aux;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_h = ft_lstnew(f(lst->content));
	if (!new_h)
		return (NULL);
	aux = new_h;
	lst = lst->next;
	while (lst)
	{
		new_n = ft_lstnew(f(lst->content));
		if (!new_n)
		{
			ft_lstclear(&new_h, del);
			return (NULL);
		}
		aux->next = new_n;
		aux = new_n;
		lst = lst->next;
	}
	return (new_h);
}
