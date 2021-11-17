#define PUSHSWP_H
#ifdef PUSHSWP_H

# include "libft/libft.h"
# include <stdlib.h>

typedef struct	s_general
{
	int argc;
	char **argv;
	t_list *a;
	t_list *b;
}				t_general;

typedef struct	s_stack
{
	int	num;
}				t_stack;

/*
** Operator Functions
*/

void	rotate(t_list	**lst, int size);
void	swap(t_list	**lst);
void	push(t_list	**src, t_list	**dst);

/*
** Helper Functions
*/

int	parse(char **str);
void	savetolist(t_list **lst, int argc, char **argv);
void	freestr(char **str);
int		init(char **argv, int argc, t_list *a);
int		ifsimbols(char c, char a);

/*
** Checker Functions
*/

int	checkdupp(t_list *a);
int check(t_list *a, int num);

/*
** Solver Functions
*/

/*
** TO ERASE
*/

void printlist(void *a);

#endif