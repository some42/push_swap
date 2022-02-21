/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:42:11 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/20 21:02:46 by agaliste         ###   ########.fr       */
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
	int	stk[3];

	stk[0] = ((int)((t_stack *)(*stack)->content)->num);
	stk[1] = ((int)((t_stack *)(*stack)->next->content)->num);
	stk[2] = ((int)((t_stack *)(*stack)->next->next->content)->num);
	if ((stk[0] > stk[1]) && (stk[1] < stk[2]) && (stk[0] < stk[2]))
		swap(stack, "sa\n");
	else if ((stk[0] > stk[1]) && (stk[1] > stk[2]) && (stk[0] > stk[2]))
	{
		swap(stack, "sa\n");
		rotate(stack, ft_lstsize(*stack) - 2, "rra\n");
	}
	else if ((stk[0] > stk[1]) && (stk[1] < stk[2]) && (stk[0] > stk[2]))
		rotate(stack, ft_lstsize(*stack), "ra\n");
	else if ((stk[0] < stk[1]) && (stk[1] > stk[2]) && (stk[0] < stk[2]))
	{
		swap(stack, "sa\n");
		rotate(stack, ft_lstsize(*stack), "ra\n");
	}
	else if ((stk[0] < stk[1]) && (stk[1] > stk[2]) && (stk[0] > stk[2]))
		rotate(stack, ft_lstsize(*stack) - 2, "rra\n");
}

void
	five_sort(t_list **stackA, t_list **stackB)
{
	push(stackA, stackB, "pb\n");
	if (ft_lstsize(*stackA) < 4)
	{
		three_sort(stackA);
		first_check(stackA, stackB);
		return ;
	}
	push(stackA, stackB, "pb\n");
	three_sort(stackA);
	first_check(stackA, stackB);
	second_check(stackA, stackB);
}

void
	big_sort(t_list **stackA, t_list **stackB, int size)
{
	int		max_bits;
	int		iter[2];

	max_bits = 0;
	iter[0] = 0;
	while (((size - 1) >> max_bits) != 0)
		++max_bits;
	while (iter[0] < max_bits)
	{
		iter[1] = 0;
		while (iter[1]++ < size)
		{
			if (((((t_stack *)(*stackA)->content)->num >> iter[0]) & 1) == 1)
				rotate(stackA, ft_lstsize(*stackA), "ra\n");
			else
				push(stackA, stackB, "pb\n");
		}
		iter[0]++;
		while (ft_lstsize(*stackB) != 1)
			push(stackB, stackA, "pa\n");
		push(stackB, stackA, "pa\n");
	}
}
