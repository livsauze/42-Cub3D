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

# define WIDTH 1400
# define HEIGHT 900

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

typedef struct s_player
{
	double	pos_x; // Position of the player
	double	pos_y;
	double	dir_x; // Direction of the player
	double	dir_y;
}				t_player;


typedef	struct s_ray
{
	double	plane_x; // x position of the plane (camera), plane is perpandicular to the direction of the payer
	double	plane_y;
	int		curr_ray_x; // Position of the current ray cast. it's an int have the cell of the current ray (map_x)
	int		curr_ray_y; // (map_y)
}				t_ray;

typedef struct s_map
{
	int	err;
	int	fd;
	int ceiling[3];
	int	floor[3];
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	t_mlx	*mlx;
	t_player *player;
	t_ray *ray;
}	t_map;


/*************************************INIT*************************************/
t_map	*ft_init_struct(char *file);
void	ft_init_mlx(t_map *map);
void	ft_start_game(t_map *map);
void	ft_end(t_map *map);
void	init_data(t_map *map);

/*************************************CHECK*************************************/
int ft_check_ext(char *file);


/*************************************GET_MAP*************************************/
t_map	*ft_get_map(t_map *map);
void	ft_get_color(t_map *map, char *line);
void	ft_get_SO(t_map *map, char *line, int i);
void	ft_get_NO(t_map *map, char *line, int i);
void	ft_get_WE(t_map *map, char *line, int i);
void	ft_get_EA(t_map *map, char *line, int i);

/*************************************UTILS*************************************/
int	ft_err(char *str);
void	ft_free_tab(char **str);





// //////////////////////////////////  mlx ////////////////////////////////// //

void	ft_window_init(t_map *map);
void	ft_malloc_error(void);

// //////////////////////////////////  events ////////////////////////////////// //

int	ft_close_handler(t_map *map);
void	ft_events_init(t_map *map);
int	ft_key_handler(int keysym, t_map *map);



#endif