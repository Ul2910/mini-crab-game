#include "solong.h"

void	create_imgs(t_map	*map)
{
	int	img_width;
	int	img_height;

	map->img.crab1 = mlx_new_image(map->mlx, 50, 50);
	map->img.seaweed1 = mlx_new_image(map->mlx, 50, 50);
	map->img.cave = mlx_new_image(map->mlx, 50, 50);
	map->img.starfish = mlx_new_image(map->mlx, 50, 50);
	map->img.back = mlx_new_image(map->mlx, 50, 50);
	map->img.crab1 = mlx_xpm_file_to_image(map->mlx, "img/crab1.xpm",
			&img_width, &img_height);
	map->img.seaweed1 = mlx_xpm_file_to_image(map->mlx, "img/seaweed1.xpm",
			&img_width, &img_height);
	map->img.cave = mlx_xpm_file_to_image(map->mlx, "img/cave.xpm",
			&img_width, &img_height);
	map->img.starfish = mlx_xpm_file_to_image(map->mlx, "img/starfish.xpm",
			&img_width, &img_height);
	map->img.back = mlx_xpm_file_to_image(map->mlx, "img/back.xpm",
			&img_width, &img_height);
}

void	print_frame(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->lines_num)
	{
		j = 0;
		while (j < ft_strlen(map->map[0]))
		{
			choose_image(map, i, j, map->map[i][j]);
			j++;
		}
		i++;
	}
}

void	choose_image(t_map *map, int y, int x, char symbol)
{
	if (symbol == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.starfish,
			x * 50, y * 50);
	else if (symbol == '0')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.back,
			x * 50, y * 50);
	else if (symbol == 'P')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.crab1,
			x * 50, y * 50);
	else if (symbol == 'E')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.cave,
			x * 50, y * 50);
	else if (symbol == 'C')
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.seaweed1,
			x * 50, y * 50);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	errno = 0;
	fill_struct(&map);
	if (argc != 2)
		errors("Usage: ./so_long *.ber\n", &map);
	map_starter(&map, argv[1]);
	write(1, "Moves: 0", 8);
	map.mlx = mlx_init();
	map.mlx_win = mlx_new_window(map.mlx, ft_strlen(map.map[0]) * 50,
			map.lines_num * 50, "./so_long");
	create_imgs(&map);
	print_frame(&map);
	mlx_key_hook(map.mlx_win, key_hook, &map);
	mlx_hook(map.mlx_win, 17, 1L << 5, win_close, &map);
	mlx_loop(map.mlx);
}
