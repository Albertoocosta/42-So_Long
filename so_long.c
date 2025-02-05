#include "./includes/so_long.h"

void	set_matrix(t_map *map, char *clean_line, int height)
{
	int	x;

	x = 0;
	while (clean_line[x] != 0)
	{
		map->matrix[height][x] = clean_line[x];
		x++;
	}
}

void	matrixfill(t_game *game, int fd)
{
	char	*line;
	char	*clean_line;
	int		height;

	height = 0;
	game->map->matrix = (char **)malloc(sizeof(char *) * game->height);
	if (!game->map->matrix)
		free_game(game, fd, "Matrix error");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_line = ft_strtrim(line, "\n");
		game->map->matrix[height] = (char *)malloc(sizeof(char) * game->width);
		if (!game->map->matrix)
			freematrix(game, fd, height, "Matrix line error");
		set_matrix(game->map, clean_line, height);
		height++;
		free(clean_line);
	}
	close(fd);
}

void	get_dimensions(t_game *game, int fd)
{
	char	*line;
	char	*clean_line;
	int		map_line_width;
	int		width_erro;

	map_line_width = 0;
	width_erro = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		clean_line = ft_strtrim(line, "\n");
		free(line);
		if (map_line_width == 0 && ft_strlen(clean_line))
			map_line_width = ft_strlen(clean_line);
		else
			width_erro = width_check(game, clean_line,
					map_line_width, width_erro);
		game->height++;
		free(clean_line);
	}
	if (width_erro == 1)
		free_game(game, fd, "Width error");
	close(fd);
}

void	map_init(int fd, char *file_path)
{
	t_game *game;
	t_map *map;

	game = malloc(sizeof(t_game));
	if (!game)
		ft_error("Error to alocate map");
	get_dimensions(game, fd);
	fd = open(file_path, O_RDONLY, 0);
	map = malloc(sizeof(t_map));
	if (!map)
		ft_error("Error to alocate map");
	game->map = map;
	matrixfill(game, fd);
	
	for (int i = 0; i < game->height; i++) {
        for (int j = 0; j < game->width; j++) {
            printf("%c ", map->matrix[i][j]);  // Imprime cada elemento seguido de um espaço
        }
        printf("\n");  // Nova linha ao final de cada linha da matriz
    }
}

int	main(int argc, char **argv)
{
	int fd;

	fd = input_check(argc, argv[1]);
	map_init(fd, argv[1]);

}
