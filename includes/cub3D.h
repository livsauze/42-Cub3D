#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <libft.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "../minilibx-linux/mlx.h"

# define WIDTH 800
# define HEIGHT 800

typedef struct s_map
{
	int	err;
	int	fd;
}	t_map;

typedef struct s_mlx
{
	char *name;
	char *addr;
	void *window;
	void *mlx;
	void *img;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}				t_mlx;


/*************************************INIT*************************************/
t_map	*ft_init_struct(char *file);
void	ft_start_game(t_map *map);
void	ft_end(t_map *map);

/*************************************CHECK*************************************/
int ft_check_ext(char *file);

/*************************************UTILS*************************************/
int	ft_err(char *str);
void	ft_free_tab(char **str);





// //////////////////////////////////  mlx ////////////////////////////////// //

void	ft_window_init(t_mlx *mlx);
void	ft_malloc_error(void);
int     no_event(t_mlx *mlx);

// //////////////////////////////////  events ////////////////////////////////// //

int	ft_close_handler(t_mlx *mlx);
void	ft_events_init(t_mlx *mlx);
int	ft_key_handler(int keysym, t_mlx *mlx);



#endif