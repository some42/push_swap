/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:28:04 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/11 13:15:36 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

void
	reterror(char *error)
{
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit (0);
}

void
	replacebyorder(t_list **stack, t_list *ordered)
{
	t_list	*head;
	int		indx;

	head = *stack;
	indx = 0;
	while (ordered != NULL)
	{
		while (*stack != NULL)
		{
			if (((t_stack *)(*stack)->content)->num ==
				((t_stack *)ordered->content)->num)
			{
				((t_stack *)(*stack)->content)->num = indx;
				break ;
			}
			(*stack) = (*stack)->next;
		}
		(*stack) = head;
		indx++;
		ordered = ordered->next;
	}
	(*stack) = head;
}
