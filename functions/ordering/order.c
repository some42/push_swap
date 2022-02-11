/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:42:11 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/11 13:14:02 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

void
	selectionsort(t_list **head)
{
	t_list	*temp;
	t_list	*min;
	t_list	*r;
	int		x;

	temp = *head;
	while (temp)
	{
		min = temp;
		r = temp->next;
		while (r)
		{
			if (((t_stack *)min->content)->num > ((t_stack *)r->content)->num)
				min = r;
			r = r->next;
		}
		x = ((t_stack *)temp->content)->num;
		((t_stack *)temp->content)->num = ((t_stack *)min->content)->num;
		((t_stack *)min->content)->num = x;
		temp = temp->next;
	}
}
