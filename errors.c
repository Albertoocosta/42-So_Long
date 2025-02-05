#include "./includes/so_long.h"

int	ft_error(char *message)
{
	int	i;

	i = 0;
	while (message[i])
	{
		write(2, &message[i], 1);
		i++;
	}
	write(2, "\n", 1);
	exit(-1);
}
void	free_game(t_game *game, int fd, char *message)
{
	free(game);
	close(fd);
	ft_error(message);
}
void	freematrix(t_game *game, int fd, int height, char *message)
{
	while (height)
	{
		if (game->map->matrix[height])
			free(game->map->matrix[height]);
		height--;
	}
	free(game->map->matrix);
	free_game(game, fd, message);
}