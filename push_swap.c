/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:14:57 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/10 19:38:56 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pushswp.h"

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
	
	while(issorted(copy) == 1)
		selectionSort(&copy);
	write(1, "\nSORTED\n", 9);
	if(issorted(lst) == 0)
		write(1, "\nSORTED\n", 9);
	ft_lstiter(copy, printlist);
	ft_lstclear(&lst, free);
	ft_lstclear(&copy, free);
	return (0);
}
