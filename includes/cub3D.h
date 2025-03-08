/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:38:29 by estepere          #+#    #+#             */
/*   Updated: 2025/03/06 20:25:17 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

# define WIDTH 1800
# define HEIGHT 1200
# define MINIW 180
# define MINIH 80
# define TILE_SIZE 64

# define UP 119
# define DOWN 115
# define LEFT 97
# define RIGHT 100

# define ROT_SPEED 0.07
# define MOV_PLAYER 0.08
# define FOV_ANGLE 0.66
# define COLLISION_MARGIN 0.2

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define RED 0xFF0000
# define GREEN 0x00FF00
# define CYAN 0x00FFFF
# define DARK_BLUE 0x00008B

typedef struct s_img
{
	char	*addr;
	void	*img;
	int		width;
	int		height;
	int		bpp;
	int		endian;
	int		line_len;
	int		*wall;
}		t_img;

typedef struct s_text
{
	t_img	*wall_so;
	t_img	*wall_no;
	t_img	*wall_we;
	t_img	*wall_ea;
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
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
}		t_player;

typedef struct s_ray
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		step_x;
	int		step_y;
	double	plane_x;
	double	plane_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	int		hit_wall;
	double	perp_w_d;
	int		side_wall;
	int		line_h;
}				t_ray;

typedef struct s_map
{
	int			max_w;
	int			max_h;
	int			map_width;
	int			map_height;
	int			color;
	int			map_x;
	int			map_y;
	int			err;
	int			fd;
	int			key_states[8];
	int			ceiling[3];
	int			floor[3];
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	void		*window;
	void		*mlx;
	t_img		*cur_t;
	t_img		*img;
	t_text		*t;
	t_player	*player;
	t_ray		*ray;
	t_minimap	*mini;
}		t_map;

/***********************************INIT***********************************/
t_map	*ft_init_struct(char *file);
int		ft_init_player(t_map *map, int x, int y, int player);
void	ft_init_textures(t_map *map, t_text *texture, t_img *mn);
void	ft_start_game(t_map *map);
void	init_data(t_map *map);
void	get_dir_player(t_map *map, int x, int y);
void	ft_malloc_game(t_map *map);

int		ft_hook(t_map *map);

/***********************************CHECK***********************************/
int		ft_check_ext(char *file, char *str);
int		ft_map_unclosed(t_map *map, int x, int y);

/***********************************GET_MAP*********************************/
t_map	*ft_get_map(t_map *map);
void	ft_get_color(t_map *map, char *line);
void	ft_get_text(t_map *map, char *line);

/***********************************UTILS***********************************/
int		ft_empty_line(char *str);
int		ft_tab_len(char **str);
int		len_map_width(char **map);
int		convert_key(int key);
long	ft_convert_rgb(int r, int g, int b);
void	ft_err(char *str, t_map *map);
void	ft_free_tab(char **str);
void	ft_end(t_map *map);
void	ft_draw_bckg(t_map *map, t_img *bckg);
void	ft_draw_pixel(t_img *img, int x, int y, int color);
void	mlx_put_pixel(t_img *img, int x, int y, int color);

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
int		ft_key_handler(t_map *map);
void	ft_change_mnmap(char **map, t_player *player);
int		ft_check_wall(char **map, t_player *player, int key);

// /////////////////////////  player_movement  /////////////////////////// //
void	ft_move(t_map *map, t_player *player, int *keystate);

// //////////////////////////  handler_movement  ////////////////////////// //
void	left_mov(t_map *map, t_player *player);
void	right_mov(t_map *map, t_player *player);
void	front_mov(t_map *map, t_player *player);
void	back_mov(t_map *map, t_player *player);
void	rotation_player(t_map *map, t_player *player, double theta);

// //////////////////////////////////  ray  //////////////////////////////// //
void	ray_casting(t_ray *ray, t_player *player, t_map *map);
void	dda_algo(t_ray *ray, t_player *player, t_map *map, int x);
void	initial_distance(t_ray *ray, t_player *player, t_map *map);
int		hit_the_wall(t_map *map, double new_x, double new_y);

// /////////////////////////////  wall_display  ///////////////////////////// //
void	draw_vertical_line(int draw_start, int draw_end, t_map *map, int x);
void	wall_dist(t_map *map, t_ray *ray, int x);

#endif