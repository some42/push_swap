/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 03:15:47 by agaliste          #+#    #+#             */
/*   Updated: 2021/09/22 13:49:50 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswp.h"

void	rotate(t_list	**lst, int size)
{
	t_list	*temp;
	int		i;

	if (!lst)
		return ;
	temp = ft_lstlast(*lst);
	temp->next = *lst;
	temp = *lst;
	i = -1;
	while (++i < size)
		temp = temp->next;
	*lst = temp->next;
	temp->next = NULL;
}

void	swap(t_list	**lst)
{
	void	*temp;

	if (ft_lstsize((*lst)) < 2 || (*lst)->content == NULL
		|| (*lst)->next->content == NULL)
		return ;
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
}

void	push(t_list	**src, t_list **dst)
{
	if ((*src)->content != NULL)
	{
		ft_lstadd_front(dst, ft_lstnew((int *)(*src)->content));
		if (ft_lstsize((*src)) == 1)
			(*src)->content = NULL;
		else
			*src = (*src)->next;
	}
}
