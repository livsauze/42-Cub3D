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

typedef struct s_player
{
	int	pos_x;
	int pos_y;
}		t_player;


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

typedef struct s_map
{
	int			err;
	int			fd;
	int 		ceiling[3];
	int			floor[3];
	char		**map;
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	t_player	*player;
	t_mlx		*mlx;
}	t_map;


/*************************************INIT*************************************/
t_map	*ft_init_struct(char *file);
void	ft_init_mlx(t_map *map);
void	ft_start_game(t_map *map);
void	ft_end(t_map *map);
int		ft_init_player(t_map *map, int x, int y, int player);

/*************************************CHECK*************************************/
int ft_check_ext(char *file);
int	ft_map_unclosed(t_map *map, int x, int y);



/*************************************GET_MAP*************************************/
t_map	*ft_get_map(t_map *map);
void	ft_get_color(t_map *map, char *line);
void	ft_get_text(t_map *map, char *line);

/*************************************UTILS*************************************/
void	ft_err(char *str, t_map *map);
void	ft_free_tab(char **str);
int	ft_empty_line(char *str);
int	ft_tab_len(char **str);



// //////////////////////////////////  mlx ////////////////////////////////// //

void	ft_window_init(t_map *map);
void	ft_malloc_error(void);

// //////////////////////////////////  events ////////////////////////////////// //

int	ft_close_handler(t_map *map);
void	ft_events_init(t_map *map);
int	ft_key_handler(int keysym, t_map *map);



#endif