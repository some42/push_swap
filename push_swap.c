/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:14:57 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/09 19:34:12 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/pushswp.h"

int	main(int argc, char **argv)
{
	t_list *lst;
	t_list *b;

	lst = NULL;
	b = NULL;
	init(argv, argc, &lst);
	ft_lstiter(lst, printlist);
	ft_lstclear(&lst, free);
	return (0);
}
