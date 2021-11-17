/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:28:04 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/05 19:58:09 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswp.h"

void printlist(void *a)
{
	printf("%i\n", ((t_stack*)a)->num);
}

int	ifsimbols(char c, char a)
{
	if (c == '-' || c == '+')
	{
		if (a == '-' || a == '+')
			return (1);
	}
	if ((c >= '!' && c <= '*') || c == ',' || (c >= '.' && c <= '/'))
		return (1);
	return (0);
}

void	freestr(char **str)
{
	int	j;

	j = 0;
	while (str[j])
		free(str[j++]);
	free(str);
}
