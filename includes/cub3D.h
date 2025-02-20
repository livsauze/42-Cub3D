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
# define HEIGHT 500
# define MINIW 180
# define MINIH 80

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define CYAN 0x00FFFF
# define MAGENTA 0xFF00FF

typedef struct s_img
{
	char	*addr;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		line_len;
	int		x;
	int		y;
}		t_img;

typedef struct s_text
{
	t_img	*wall_so;
	t_img	*wall_no;
	t_img	*wall_we;
	t_img	*wall_ea;
	t_img	*bckg;
}		t_text;

typedef struct s_minimap
{
	t_img	*mnmap;
	float	scale_x;
	float	scale_y;
	int		pixel_x;
	int		pixel_y;
	int		color;
}		t_minimap;

typedef struct s_player
{
	double	pos_x; // Position of the player
	double	pos_y;
	double	dir_x; // Direction of the player
	double	dir_y;
}		t_player;

typedef	struct	s_ray
{
	double	camera_x; // relative position of a column pixel on the screen
	double	camera_y;
	double	ray_dir_x; // constant variable. direction of the ray
	double	ray_dir_y;
	int		step_x; // constant variable. Direction of the square who need to go. 2 values => -1 and 1 (for left and right)
	int		step_y; // 2 values -1 and 1 for (low and high)
	double	plane_x; // x position of the plane (camera), plane is perpandicular to the direction of the payer
	double	plane_y;
	double	side_dist_x; // initialy distance (base on player position) of the ray must travel to the next vertical line of the square
	double	side_dist_y;
	double	delta_dist_x; // constant variable. distance (base between 2 vertical ligne of the square) between 2 square of the grid (map) in x side (allow to increment side_x)
	double	delta_dist_y;
	int		hit_wall;
	double	perp_wall_dist; // Distance of the perpendicular line of the camera plane to the wall
	int		side_wall; // wall is in E/W for 0 and N/S for 1
}		t_ray;

typedef struct s_map
{
	int			max_w;
	int			max_h;
	int			color; // color of the wall
	int			map_x; // position of the current ray in the grid
	int			map_y;
	int			err;
	int			fd;
	int			ceiling[3];
	int			floor[3];
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	void		*window;
	void		*mlx;
	t_img		*img;
	t_text		*t;
	t_player	*player;
	t_ray		*ray;
	t_minimap	*mini;
}		t_map;

/***********************************INIT***********************************/
t_map	*ft_init_struct(char *file);
void	ft_init_mlx(t_map *map);
void	ft_init_textures(t_map *map, t_text *texture, t_img *mn);
void	ft_start_game(t_map *map);
void	ft_end(t_map *map);
void	init_data(t_map *map);
void	get_dir_player(t_map *map, int x, int y);
int		ft_init_player(t_map *map, int x, int y, int player);
int		ft_hook(t_map *map);

/***********************************CHECK***********************************/
int		ft_check_ext(char *file);
int		ft_map_unclosed(t_map *map, int x, int y);

/***********************************GET_MAP*********************************/
t_map	*ft_get_map(t_map *map);
void	ft_get_color(t_map *map, char *line);
void	ft_get_text(t_map *map, char *line);

/***********************************UTILS***********************************/
void	ft_err(char *str, t_map *map);
void	ft_free_tab(char **str);
int		ft_empty_line(char *str);
int		ft_tab_len(char **str);
int		len_map_width(char **map);
void	ft_draw_bckg(t_map *map, t_img *bckg);
void	ft_draw_pixel(t_img *img, int x, int y, int color);
void	my_put_pixel(t_img *img, int x, int y, long color);

/***********************************MINIMAP**********************************/
int		ft_minimap(t_map *map, t_minimap *mini);
void	ft_draw_minimap(t_map *map, t_minimap *mn, t_img *img);

// /////////////////////////    					////////////////////// //
							// Ray casting part //
// /////////////////////////   					 //////////////////////// //

// /////////////////////////////////  mlx  //////////////////////////////// //
void	ft_window_init(t_map *map);
void	ft_malloc_error(void);

// ///////////////////////////////  events  /////////////////////////////// //
int		ft_close_handler(t_map *map);
void	ft_events_init(t_map *map);
int		ft_key_handler(int keysym, t_map *map);
void	ft_change_map(char **map, t_player *player);
int		ft_check_wall(char **map, t_player *player, int key);

// //////////////////////////////////  ray  //////////////////////////////// //

void	ray_casting(t_ray *ray, t_player *player, t_map *map);
void	dda_algo(t_ray *ray, t_player *player, t_map *map, int x);
void	initial_distance(t_ray *ray, t_player *player, t_map *map);
int		hit_the_wall(t_map *map);

// /////////////////////////////  wall_display  ///////////////////////////// //
void	mlx_put_pixel(t_img *img, int x, int y, int color);
void	draw_vertical_line(int draw_start, int draw_end, t_map *map, int x);
void	wall_dist(t_map *map, t_player *player, t_ray *ray, int x);

#endif