/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:28:04 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/09 19:34:56 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

void printlist(void *a)
{
	printf("%i\n", ((t_stack*)a)->num);
}

void	reterror(char *error)
{
	write(1, "Error\n", 7);
	write(1, error, ft_strlen(error));
	write(1, "\n", 1);
	exit (0);
}

int	ifsimbols(char c, char a)
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

void	freestr(char **str)
{
	int	j;

	j = 0;
	while(str[j])
		free(str[j++]);
	free(str);
}
