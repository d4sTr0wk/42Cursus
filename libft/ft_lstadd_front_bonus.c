#include"libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{	
	if (alst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}
