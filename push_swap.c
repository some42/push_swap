/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:14:57 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/10 10:00:46 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pushswp.h"

//------- CHECK LEAKS --------//
//static inline void
// 	leaks()
// {
// 	system("leaks push_swap");
// }
//---------------------------//

int
	main(int argc, char **argv)
{
	//- CHECK LEAKS -//
	// atexit(leaks);
	//-------------//
	
	t_list *lst;
	t_list *b;

	lst = NULL;
	b = NULL;
	init(argv, argc, &lst);

	//------------ TESTS  -------------//
	if (issorted(lst) == 1)
		write(1, "\nNOT SORTED\n", 13);
	else
		write(1, "\nSORTED\n", 9);
	ft_lstiter(lst, printlist);
	//------------------------------//

	ft_lstclear(&lst, free);
	return (0);
}
