#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "../Libft/libft.h"
# include "../Printf/ft_printf.h"
# include "../minilibx-linux/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363


typedef struct s_map
{

	char	**matrix;
}				t_map;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		img_width;
	int		img_height;
	int		bpp;
	int		line_lenght;
	int		endian;
}				t_img;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_img	img;
	int		height;
	int		width;
	t_map	*map;
}				t_game;

//errors.c
int		ft_error(char *message);
void	free_game(t_game *game, int fd, char *message);
void	freematrix(t_game *game, int fd, int height, char *message);

//validation.c
int	width_check(t_game *game, char *clean_line, int map_line, int width_error);
int	check_map(char *filename);
int	input_check(int argc, char *filename);

//game.c
void	set_matrix(t_map *map, char *clean_line, int height);
void	matrixfill(t_game *game, int fd);
void	get_dimensions(t_game *game, int fd);
void	map_init(int fd, char *file_path);

#endif