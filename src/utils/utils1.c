#include "../../includes/cub3D.h"

void	ft_free_tab(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	ft_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == '\t' || str[i] == ' '))
		i++;
	if (str[i] != '\n')
		return (0);
	return (1);
}

int	ft_tab_len(char **str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}