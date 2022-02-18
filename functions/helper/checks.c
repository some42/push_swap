/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:34:48 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/18 11:25:21 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

static inline int
	check(t_list *a, int num)
{
	while (a->next)
	{
		if (num == ((t_stack *)a->next->content)->num)
			return (1);
		a = a->next;
	}
	return (0);
}

int
	issorted(t_list *stack)
{
	while (stack->next)
	{
		if (((t_stack *)stack->content)->num
			< ((t_stack *)stack->next->content)->num)
			stack = stack -> next;
		else
			return (0);
	}
	return (1);
}

int
	ifsimbols(char c, char a)
{
	if (c == '-' || c == '+')
	{
		if (a == '-' || a == '+' || !ft_isdigit(a))
			return (1);
	}
	if ((c >= '!' && c <= '*') || c == ',' || (c >= '.' && c <= '/'))
		return (1);
	return (0);
}

int
	checkdupp(t_list *a)
{
	while (a->next)
	{
		if (check(a, ((t_stack *)a->content)->num))
			return (1);
		a = a->next;
	}
	return (0);
}
