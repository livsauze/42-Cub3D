#include "../includes/main.h"

int	ft_err(char *str)
{
	write(2, "Error\n", 6);
	while (*str)
		write(2, str++, 1);
	return (1);
}