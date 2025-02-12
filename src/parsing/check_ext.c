#include "../../includes/cub3D.h"

int	ft_check_ext(char *file)
{
	char	**tab;

	tab = ft_split(file, '.');
	if (!tab[1] || ft_strncmp(tab[1], "cub", 3))
		return (ft_free_tab(tab), 1);
	ft_free_tab(tab);
	return (0);
}
