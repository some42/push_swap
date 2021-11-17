/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:34:48 by agaliste          #+#    #+#             */
/*   Updated: 2021/10/23 03:40:16 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswp.h"

int check(t_list *a, int num)
{
	while (a->next)
	{
		if (num == ((t_stack*)a->next->content)->num)
			return(1);
		a = a->next;
	}
	return(0);
}

int	checkdupp(t_list *a)
{
	while (a->next)
	{
		if (check(a, ((t_stack*)a->content)->num))
			return (1);
		a = a->next;
	}
	return (0);
}
