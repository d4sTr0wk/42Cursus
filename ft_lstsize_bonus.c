#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	cnt;

	cnt = 0;
	while(lst)
	{
		++cnt;
		lst = lst->next;
	}
	return (cnt);
}
