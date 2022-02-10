/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:28:04 by agaliste          #+#    #+#             */
/*   Updated: 2022/02/10 09:34:00 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/pushswp.h"

void
	printlist(void *a)
{
	printf("%i\n", ((t_stack*)a)->num);
}

void
	reterror(char *error)
{
	write(STDERR_FILENO, "Error\n", 7);
	write(STDERR_FILENO, error, ft_strlen(error));
	write(STDERR_FILENO, "\n", 1);
	exit (0);
}
