/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:14:57 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/21 10:06:28 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pushswp.h"

static inline void
	clearall(t_list **stackA, t_list **stackB, t_list **copy)
{
	ft_lstclear(stackA, free);
	ft_lstclear(stackB, free);
	ft_lstclear(copy, free);
}

int
	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*copy;

	stack_a = NULL;
	stack_b = NULL;
	copy = NULL;
	init(argv, argc, &stack_a, &copy);
	if (!issorted(stack_a))
	{
		if (ft_lstsize(stack_a) < 3)
			rotate(&stack_a, ft_lstsize(stack_a), "ra\n");
		else if (ft_lstsize(stack_a) <= 3)
			three_sort(&stack_a);
		else if (ft_lstsize(stack_a) <= 5)
			five_sort(&stack_a, &stack_b);
		else
		{
			selection_sort(&copy);
			replacebyorder(&stack_a, copy);
			big_sort(&stack_a, &stack_b, ft_lstsize(stack_a));
		}
	}
	clearall(&stack_a, &stack_b, &copy);
	return (0);
}
