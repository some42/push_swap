/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agaliste <agaliste@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:18:20 by agaliste          #+#    #+#             */
/*   Updated: 2021/11/27 02:14:40 by agaliste         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswp.h"

void	parse(char **str)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (str[++i])
	{
		j = -1;
		count = 0;
		while (str[i][++j] != '\0')
		{
			if (ft_isalpha(str[i][j]))
				reterror("Some arguments are characters");
			if (str[i][j] == '-' || str[i][j] == '+')
				count += 1;
			if (count > 1 || ifsimbols(str[i][j], str[i][j + 1]))
				reterror("Incorrect use of - or +");
		}
		if (ft_atoli(str[i]) > 2147483647 || ft_atoli(str[i]) < -2147483648)
			reterror("Some arguments are bigger than an integer");
	}
}

void	savetolist(t_list **lst, int argc, char **argv)
{
	char	**str;
	int		i;
	int		j;
	t_stack	*num;

	i = 1;
	num = NULL;
	while (i < argc)
	{
		str = ft_split((argv[i++]), ' ');
		j = 0;
		while (str[j])
		{
			num = malloc(sizeof(t_stack));
			num->num = ft_atoi(str[j++]);
			ft_lstadd_back(lst, ft_lstnew(num));
		}
		freestr(str);
	}
}

void	init(char **argv, int argc, t_list **lst)
{
	char	**str;
	int		i;

	i = 1;
	if (argv[i] && argc > 1)
	{
		while (argv[i])
		{
			str = ft_split((argv[i]), ' ');
			parse(str);
			freestr(str);
			i++;
		}
	}
	else
		reterror("No args");
	savetolist(lst, argc, argv);
	if (checkdupp(*lst))
		reterror("There are duplicates");
}
