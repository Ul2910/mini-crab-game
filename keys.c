#include "solong.h"

int	key_hook(int key, t_map *map)
{
	map->prev_x = map->x;
	map->prev_y = map->y;
	if (key == 53)
		win_close(53, map);
	else if (key == 13 && map->map[map->y - 1][map->x] != '1' && map->won == 0)
		map->y = map->y - 1;
	else if (key == 0 && map->map[map->y][map->x - 1] != '1' && map->won == 0)
		map->x = map->x - 1;
	else if (key == 1 && map->map[map->y + 1][map->x] != '1' && map->won == 0)
		map->y = map->y + 1;
	else if (key == 2 && map->map[map->y][map->x + 1] != '1' && map->won == 0)
		map->x = map->x + 1;
	else
		return (0);
	if (map->map[map->y][map->x] == 'E' && map->c_left > 0)
	{
		map->x = map->prev_x;
		map->y = map->prev_y;
		return (0);
	}
	print_crab(key, map);
	return (0);
}

void	print_crab(int keycode, t_map *map)
{
	int	i;

	(void)keycode;
	map->moves = map->moves + 1;
	i = -1;
	while (++i < 7 + 11)
		write(1, "\b", 1);
	write(1, "Moves: ", 7);
	ft_putnbr(map->moves);
	if (map->map[map->y][map->x] == 'C')
	{
		map->map[map->y][map->x] = '0';
		map->c_left--;
	}
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.back,
		map->prev_x * 50, map->prev_y * 50);
	if (map->map[map->y][map->x] == 'E' && map->c_left == 0)
	{
		mlx_string_put(map->mlx, map->mlx_win, map->prev_x * 50 + 5,
			map->prev_y * 50 + 30, 0x00FFFF00, "YAAAY!");
		map->won = 1;
	}
	else
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.crab1,
			map->x * 50, map->y * 50);
}

void	ft_putnbr(int n)
{
	char	c;

	if (n >= 10)
	{
		ft_putnbr(n / 10);
		c = n % 10 + 48;
		write(1, &c, 1);
	}
	else
	{
		c = n % 10 + 48;
		write(1, &c, 1);
	}
}

int	win_close(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_image(map->mlx, map->img.crab1);
		mlx_destroy_image(map->mlx, map->img.seaweed1);
		mlx_destroy_image(map->mlx, map->img.cave);
		mlx_destroy_image(map->mlx, map->img.starfish);
		mlx_destroy_image(map->mlx, map->img.back);
		mlx_destroy_window(map->mlx, map->mlx_win);
		ft_free(map);
	}
	exit(0);
}
