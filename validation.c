#include "./includes/so_long.h"

int	width_check(t_game *game, char *clean_line, int map_line, int width_error)
{
	if (!ft_words(clean_line, ' '))
		width_error = 1;
	game->width = ft_strlen(clean_line);
	if (map_line != game->width)
		width_error = 1;
	return (width_error);
}
int	input_check(int argc, char *filename)
{
	int	fd;

	if (argc != 2)
		ft_error("Invalid input.");
	check_map(filename);
	fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
		ft_error("Error to open the file.");
	return (fd);
}

int	check_map(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 4] == '.' && filename[len - 3] == 'b'
		&& filename[len - 2] == 'e' && filename[len - 1] == 'r')
		return (1);
	else
		ft_error("File not .ber");
	return (0);
}

int	check_colexit(t_game *game)
{
	int	i;
	int	j;
	int exit;

	i = 0;
	j = 0;
	exit = 0;
	while(i < game->height)
	{
		j = 0; 
		while (j < game->width)
		{
			if (game->map->matrix[i][j] == 'C')
				game->map->n_coletables++;
			if (game->map->matrix[i][j] == 'E')
			{
				if (exit == 1)
					return (1);
				exit = 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player(t_game *game)
{
	int	i;
	int	j;
	int player;

	i = 0;
	j = 0;
	player = 0;
	while(i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map->matrix[i][j] == 'P')
			{
				if (player == 1)
					return (1);
				player = 1;
			}
			j++;
		}
		i++;
	}
	return (0);
}
