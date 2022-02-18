/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:14:57 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/18 13:05:08 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pushswp.h"

static inline void
	printlist(void *a)
{
	printf("%i\n", ((t_stack *)a)->num);
}

//------- CHECK LEAKS --------//
// static inline void
//  	leaks()
//  {
//  	system("leaks push_swap");
//  }
//---------------------------//

int
	main(int argc, char **argv)
{
	//- CHECK LEAKS -//
	// atexit(leaks);
	//-------------//
	
	t_list *stack_a;
	t_list *stack_b;
	t_list *copy;
	int		stkAsize;

	stack_a = NULL;
	stack_b = NULL;
	copy = NULL;
	init(argv, argc, &stack_a, &copy);
	stkAsize = ft_lstsize(stack_a);
	if (!issorted(stack_a))
	{
		selection_sort(&copy);
		replacebyorder(&stack_a, copy);
		// ft_lstiter(stack_a, printlist);
		if(stkAsize < 3)
			rotate(&stack_a, stkAsize, "ra\n");
		else if(stkAsize <= 3)
			three_sort(&stack_a);
		else if(stkAsize <= 5)
			five_sort(&stack_a, &stack_b);
	}
	ft_lstclear(&stack_a, free);
	ft_lstclear(&copy, free);
	return (0);
}
