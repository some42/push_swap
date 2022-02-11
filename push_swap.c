/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:14:57 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/11 13:16:27 by agaliste         ###   ########.fr       */
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
	
	t_list *lst;
	t_list *b;
	t_list *copy;

	lst = NULL;
	b = NULL;
	copy = NULL;
	init(argv, argc, &lst, &copy);
	
	// while(issorted(copy) == 1)
	selectionSort(&copy);
	// write(1, "\nSORTED\n", 9);
	// if(issorted(lst) == 0)
	// 	write(1, "\nSORTED\n", 9);
	
	replacebyorder(&lst, copy);
	ft_lstiter(lst, printlist);
	ft_lstclear(&lst, free);
	ft_lstclear(&copy, free);
	return (0);
}
