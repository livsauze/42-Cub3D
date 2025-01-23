#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <libft.h>
# include <fcntl.h>

typedef struct s_map
{
	int	err;
	int	fd;
}	t_map;

/*************************************INIT*************************************/
t_map	*ft_init_struct(char *file);
void	ft_start_game(t_map *map);
void	ft_end(t_map *map);

/*************************************CHECK*************************************/
int ft_check_ext(char *file);

/*************************************UTILS*************************************/
int	ft_err(char *str);
void	ft_free_tab(char **str);
#endif