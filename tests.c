/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 14:11:25 by agaliste          #+#    #+#             */
/*   Updated: 2021/10/21 19:21:32 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswp.h"

void printlist(void *lista){
	printf("a: %s\n", (char *)lista);
}
void printlist2(void *lista){
	printf("b: %s\n", (char *)lista);
}

void menu(char *argv, t_list *lst, t_list *lst2)
{
	if(!strncmp(argv, "sa", 2))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist); printf("\n");
		ft_lstiter(lst2, printlist2); swap(&lst);
		printf("\n-----SA-----\n"); 
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "sb", 2))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist); printf("\n");
		ft_lstiter(lst2, printlist2);
		swap(&lst2);
		printf("\n-----SB-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "ra", 2))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
		rotate(&lst, ft_lstsize(lst));
		printf("\n-----RA-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "rb", 2))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
		rotate(&lst2, ft_lstsize(lst2));
		printf("\n-----RB-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "rra", 3))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
		rotate(&lst, ft_lstsize(lst) - 2);
		printf("\n-----RRA-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "rrb", 3))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
		rotate(&lst2, ft_lstsize(lst2) - 2);
		printf("\n-----RRB-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "pa", 2))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
		push(&lst2, &lst);
		printf("\n-----PA-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
	if(!strncmp(argv, "pb", 2))
	{
		printf("-----STACKS-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
		push(&lst, &lst2);
		printf("\n-----PB-----\n");
		ft_lstiter(lst, printlist);
		printf("\n");
		ft_lstiter(lst2, printlist2);
	}
}

int main(int argc, char **argv){
	t_list *lst;
	t_list *lst2;

	lst2 = ft_lstnew(ft_strdup("1"));
	ft_lstadd_back(&lst2, ft_lstnew(ft_strdup("6")));
	lst = ft_lstnew(argv[2]);
	for(int i = 3; i < argc; i++)
		ft_lstadd_back(&lst, ft_lstnew(argv[i]));	
	menu(argv[1], lst, lst2);
	return 0;
}
