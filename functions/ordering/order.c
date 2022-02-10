/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 17:42:11 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/10 19:16:32 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

void
    selectionSort(t_list **head)
{
    t_list	*temp = *head;
 
    // Traverse the List
    while (temp) {
        t_list	*min = temp;
        t_list	*r = temp->next;
 
        // Traverse the unsorted sublist
        while (r) {
            if (((t_stack*)min->content)->num > ((t_stack*)r->content)->num)
                min = r;
 
            r = r->next;
        }
 
        // Swap Data
        int x = ((t_stack*)temp->content)->num;
        ((t_stack*)temp->content)->num = ((t_stack*)min->content)->num;
        ((t_stack*)min->content)->num = x;
        temp = temp->next;
    }
}
