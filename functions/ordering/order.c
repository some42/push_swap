/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:42:11 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/11 19:37:38 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

void
	selection_sort(t_list **head)
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

void
	three_sort(t_list **stack)
{
	if(((t_stack *)(*stack)->content)->num == 1)
	{
		if(((t_stack *)(*stack)->next->content)->num == 0)
			swap(stack, "sa\n");
		else
			rotate(stack, ft_lstsize(*stack) - 2, "rra\n");
		return ;
	}
	if(((t_stack *)(*stack)->content)->num == 2)
	{
		if(((t_stack *)(*stack)->next->content)->num == 1)
		{
			swap(stack, "sa\n");
			rotate(stack, ft_lstsize(*stack) - 2, "rra\n");
		}
		else
			rotate(stack, ft_lstsize(*stack), "ra\n");
		return ;
	}
	if(((t_stack *)(*stack)->content)->num == 0)
	{
		swap(stack, "sa\n");
		rotate(stack, ft_lstsize(*stack), "ra\n");
		return ;
	}
}
