#include"libft.h"

size_t	strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	i = -1;
	if (!src)
		return (NULL);
	if (!size)
		return (NULL);
	while (src[++i] && i < size)
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen(src));
}
