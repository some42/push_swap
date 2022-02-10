#define PUSHSWP_H
#ifdef PUSHSWP_H

# include "../libft/libft.h"
# include <stdlib.h>

/*
** Struct Declarations
*/

typedef struct	s_stack
{
	int	num;
}				t_stack;

/*
** Operator Functions
*/

void	rotate(t_list	**lst, int size, char *opname);
void	swap(t_list	**lst, char *opname);
void	push(t_list	**src, t_list	**dst, char *opname);

/*
** Helper Functions
*/

void init(char **argv, int argc, t_list **lst, t_list **copy);
void	reterror(char *error);

/*
** Checker Functions
*/

int		checkdupp(t_list *a);
int		ifsimbols(char c, char a);
int		issorted(t_list *stack);

/*
** Solver Functions
*/

void insertionSort(t_list **head_ref);
void selectionSort(t_list **head);

/*
** TO ERASE
*/

void	printlist(void *a);

#endif