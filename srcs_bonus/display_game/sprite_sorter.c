/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_sorter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:06:24 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/29 20:53:03 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

void	distance_from_player(t_main *main, void *content)
{
	t_sprite	*aux;

	aux = content;
	aux->dst = pow(aux->x - main->ray.posX, 2)
		+ pow(aux->y - main->ray.posY, 2);
}

static void	swaper(t_list *a, t_list *b)
{
	t_sprite	*aux;

	aux = a->content;
	a->content = b->content;
	b->content = aux;
}

static int	bubbleSortAux(t_list *ptr, t_list *lptr)
{
	t_sprite	*aux1;
	t_sprite	*aux2;
	int			swapped;

	swapped = 0;
	while (ptr->next != lptr)
	{
		aux1 = ptr->content;
		aux2 = ptr->next->content;
		if (aux1->dst < aux2->dst)
		{
			swaper(ptr, ptr->next);
			swapped = 1;
		}
		ptr = ptr->next;
	}
	return (swapped);
}

static void	bubbleSort(t_list *start)
{
	int			swapped;
	t_list		*ptr;
	t_list		*lptr;

	if (start == NULL)
		return ;
	lptr = NULL;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		ptr = start;
		bubbleSortAux(ptr, lptr);
		lptr = ptr;
	}
}

void	lstiter_adapted(t_main *main, t_list *lst, void (*f)(t_main *, void *))
{
	t_list	*ptr;

	if (lst)
	{
		while (lst)
		{
			ptr = lst->next;
			f(main, lst->content);
			lst = ptr;
		}
	}
	bubbleSort(main->flnf.sprlst);
}
