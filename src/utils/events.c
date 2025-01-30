#include "../includes/cub3D.h"

int	ft_close_handler(t_mlx *mlx)
{
	if (mlx->img)
		mlx_destroy_image(mlx->mlx, mlx->img);
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mlx)
	{
		mlx_loop_end(mlx->mlx);
		mlx_destroy_display(mlx->mlx);
		free(mlx->mlx);
	}
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_events_init(t_mlx *mlx)
{
	mlx_hook(mlx->window, KeyPress, KeyPressMask, ft_key_handler, mlx);
	mlx_hook(mlx->window, DestroyNotify, StructureNotifyMask, ft_close_handler, mlx);
}

int	ft_key_handler(int keysym, t_mlx *mlx)
{
	if (keysym == XK_Escape)
		ft_close_handler(mlx);
	return (0);
}