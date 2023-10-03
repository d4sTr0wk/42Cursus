#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new_string;
	int	i;

	new_string = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!new_string)
		return (NULL);
	i = -1;
	while (*(s + (++i)))
	{
		new_string[i] = (*f)(i, s[i]);
	}
	new_string[i] = '\0';
	return (new_string);
}
