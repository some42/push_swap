/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivesort_checks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 11:25:29 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/18 20:48:32 by agaliste         ###   ########.fr       */
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
	int	nb[4];

	nb[3] = ((int)((t_stack *)(*stackB)->content)->num);
	nb[0] = ((int)((t_stack *)(*stackA)->content)->num);
	nb[1] = ((int)((t_stack *)(*stackA)->next->content)->num);
	nb[2] = ((int)((t_stack *)(*stackA)->next->next->content)->num);
	if (nb[3] < nb[0])
		push(stackB, stackA, "pa\n");
	else if (nb[3] > nb[0] && nb[3] < nb[1])
		pa_sa(stackA, stackB);
	else if (nb[3] > nb[0] && nb[3] > nb[1] && nb[3] > nb[2])
		pa_ra(stackA, stackB);
	else
	{
		rotate(stackA, ft_lstsize(*stackA) - 2, "rra\n");
		pa_ra(stackA, stackB);
		rotate(stackA, ft_lstsize(*stackA), "ra\n");
	}
}

void
	second_check(t_list **stackA, t_list **stackB)
{
	int	nb[5];

	nb[4] = ((int)((t_stack *)(*stackB)->content)->num);
	nb[0] = ((int)((t_stack *)(*stackA)->content)->num);
	nb[1] = ((int)((t_stack *)(*stackA)->next->content)->num);
	nb[2] = ((int)((t_stack *)(*stackA)->next->next->content)->num);
	nb[3] = ((int)((t_stack *)(*stackA)->next->next->next->content)->num);
	if (nb[4] < nb[0])
		push(stackB, stackA, "pa\n");
	else if (nb[4] > nb[0] && nb[4] < nb[1])
		pa_sa(stackA, stackB);
	else if (nb[4] > nb[0] && nb[4] > nb[1] && nb[4] < nb[2])
	{
		rotate(stackA, ft_lstsize(*stackA), "ra\n");
		pa_sa(stackA, stackB);
		rotate(stackA, ft_lstsize(*stackA) - 2, "rra\n");
	}
	else if (nb[4] > nb[0] && nb[4] > nb[1] && nb[4] > nb[2] && nb[4] < nb[3])
	{
		rotate(stackA, ft_lstsize(*stackA) - 2, "rra\n");
		push(stackB, stackA, "pa\n");
		ra_ra(stackA);
	}
	else
		pa_ra(stackA, stackB);
}
