#include "solong_bonus.h"

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
	(void)keycode;
	map->moves = map->moves + 1;
	ft_putnbr_to_window(map->moves, map);
	map->digits.x = 0;
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

void	ft_putnbr_to_window(int n, t_map *map)
{
	int	choose_tile;

	if (n >= 10)
	{
		ft_putnbr_to_window(n / 10, map);
		choose_tile = n % 10;
		digit_chooser(choose_tile, map, map->digits.x);
		map->digits.x = map->digits.x + 50;
	}
	else
	{
		choose_tile = n % 10;
		digit_chooser(choose_tile, map, map->digits.x);
		map->digits.x = map->digits.x + 50;
	}
}

void	digit_chooser(int n, t_map *map, int x)
{
	if (n == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.zero, x, 0);
	else if (n == 1)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.one, x, 0);
	else if (n == 2)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.two, x, 0);
	else if (n == 3)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.three,
			x, 0);
	else if (n == 4)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.four, x, 0);
	else if (n == 5)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.five, x, 0);
	else if (n == 6)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.six, x, 0);
	else if (n == 7)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.seven,
			x, 0);
	else if (n == 8)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.eight,
			x, 0);
	else if (n == 9)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->digits.nine, x, 0);
}

int	win_close(int keycode, t_map *map)
{
	if (keycode == 53)
	{
		mlx_destroy_image(map->mlx, map->img.crab1);
		mlx_destroy_image(map->mlx, map->img.crab2);
		mlx_destroy_image(map->mlx, map->img.seaweed1);
		mlx_destroy_image(map->mlx, map->img.seaweed2);
		mlx_destroy_image(map->mlx, map->img.cave);
		mlx_destroy_image(map->mlx, map->img.starfish);
		mlx_destroy_image(map->mlx, map->img.back);
		mlx_destroy_image(map->mlx, map->digits.zero);
		mlx_destroy_image(map->mlx, map->digits.one);
		mlx_destroy_image(map->mlx, map->digits.two);
		mlx_destroy_image(map->mlx, map->digits.three);
		mlx_destroy_image(map->mlx, map->digits.four);
		mlx_destroy_image(map->mlx, map->digits.five);
		mlx_destroy_image(map->mlx, map->digits.six);
		mlx_destroy_image(map->mlx, map->digits.seven);
		mlx_destroy_image(map->mlx, map->digits.eight);
		mlx_destroy_image(map->mlx, map->digits.nine);
		mlx_destroy_window(map->mlx, map->mlx_win);
		ft_free(map);
	}
	exit(0);
}
