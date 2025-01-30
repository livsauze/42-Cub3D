#include "../../includes/cub3D.h"

void	ft_malloc_error(void)
{
	perror("malloc problems");
	exit(EXIT_FAILURE);
}

// ignor to do mlx_loop_hook
int     no_event(t_mlx *mlx) 
{
    (void)mlx;
    return (0); 
}

void	ft_window_init(t_mlx *mlx)
{	
	mlx->mlx = mlx_init();
	if (mlx->mlx == NULL)
		ft_malloc_error();
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, mlx->name);
	if (mlx->window == NULL)
	{
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		ft_malloc_error();
	}
	mlx->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	if (mlx->img == NULL)
	{
		mlx_destroy_window(mlx->mlx, mlx->window);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
		ft_malloc_error();
	}
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_len, &mlx->endian);
}

