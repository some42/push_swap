/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivesort_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:25:29 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/18 12:34:07 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

static inline void
	pa_sa(t_list **stackA, t_list **stackB)
{
	push(stackB, stackA, "pa\n");
	swap(stackA, "sa\n");
}

static inline void
	pa_ra(t_list **stackA, t_list **stackB)
{
	push(stackB, stackA, "pa\n");
	rotate(stackA, ft_lstsize(*stackA), "ra\n");
}

static inline void
	ra_ra(t_list **stackA)
{
	rotate(stackA, ft_lstsize(*stackA), "ra\n");
	rotate(stackA, ft_lstsize(*stackA), "ra\n");
}

void
	first_check(t_list **stackA, t_list **stackB)
{
	int B;
	int A[3];

	B =  ((int)((t_stack*)(*stackB)->content)->num);
	A[0] = ((int)((t_stack*)(*stackA)->content)->num);
	A[1] = ((int)((t_stack*)(*stackA)->next->content)->num);
	A[2] = ((int)((t_stack*)(*stackA)->next->next->content)->num);
	if (B < A[0]) // 1ra posición
		push(stackB, stackA, "pa\n");
	else if (B > A[0] && B < A[1]) // 2da posición
		pa_sa(stackA, stackB);
	else if (B > A[0] && B > A[1] && B > A[2]) // Ultima posición
		pa_ra(stackA, stackB);
	else // 3ra posición
	{
		rotate(stackA, ft_lstsize(*stackA) - 2, "rra\n");
		pa_ra(stackA, stackB);
		rotate(stackA, ft_lstsize(*stackA), "ra\n");
	}
}
		

void
	second_check(t_list **stackA, t_list **stackB)
{
	int B;
	int A[4];

	B =  ((int)((t_stack*)(*stackB)->content)->num);
	A[0] = ((int)((t_stack*)(*stackA)->content)->num);
	A[1] = ((int)((t_stack*)(*stackA)->next->content)->num);
	A[2] = ((int)((t_stack*)(*stackA)->next->next->content)->num);
	A[3] = ((int)((t_stack*)(*stackA)->next->next->next->content)->num);
	if (B < A[0]) // 1ra posición
		push(stackB, stackA, "pa\n");
	else if (B > A[0] && B < A[1]) // 2da posición
		pa_sa(stackA, stackB);
	else if (B > A[0] && B > A[1] && B < A[2]) // 3ra posición
	{
		rotate(stackA, ft_lstsize(*stackA), "ra\n");
		pa_sa(stackA, stackB);
		rotate(stackA, ft_lstsize(*stackA) - 2, "rra\n");
	}
	else if (B > A[0] && B > A[1] && B > A[2] && B < A[3]) // 4ta posición
	{
		rotate(stackA, ft_lstsize(*stackA) - 2, "rra\n");
		push(stackB, stackA, "pa\n");
		ra_ra(stackA);
	}
	else // Ultima posición
		pa_ra(stackA, stackB);
		
}
