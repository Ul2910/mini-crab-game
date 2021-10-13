#include "solong_bonus.h"

void	create_digits(t_map *map)
{
	map->digits.zero = mlx_new_image(map->mlx, 50, 50);
	map->digits.one = mlx_new_image(map->mlx, 50, 50);
	map->digits.two = mlx_new_image(map->mlx, 50, 50);
	map->digits.three = mlx_new_image(map->mlx, 50, 50);
	map->digits.four = mlx_new_image(map->mlx, 50, 50);
	map->digits.five = mlx_new_image(map->mlx, 50, 50);
	map->digits.six = mlx_new_image(map->mlx, 50, 50);
	map->digits.seven = mlx_new_image(map->mlx, 50, 50);
	map->digits.eight = mlx_new_image(map->mlx, 50, 50);
	map->digits.nine = mlx_new_image(map->mlx, 50, 50);
	create_digits_xpm(map);
}

void	create_digits_xpm(t_map *map)
{
	int	img_width;
	int	img_height;

	map->digits.zero = mlx_xpm_file_to_image(map->mlx, "img/0.xpm",
			&img_width, &img_height);
	map->digits.one = mlx_xpm_file_to_image(map->mlx, "img/1.xpm",
			&img_width, &img_height);
	map->digits.two = mlx_xpm_file_to_image(map->mlx, "img/2.xpm",
			&img_width, &img_height);
	map->digits.three = mlx_xpm_file_to_image(map->mlx, "img/3.xpm",
			&img_width, &img_height);
	map->digits.four = mlx_xpm_file_to_image(map->mlx, "img/4.xpm",
			&img_width, &img_height);
	map->digits.five = mlx_xpm_file_to_image(map->mlx, "img/5.xpm",
			&img_width, &img_height);
	map->digits.six = mlx_xpm_file_to_image(map->mlx, "img/6.xpm",
			&img_width, &img_height);
	map->digits.seven = mlx_xpm_file_to_image(map->mlx, "img/7.xpm",
			&img_width, &img_height);
	map->digits.eight = mlx_xpm_file_to_image(map->mlx, "img/8.xpm",
			&img_width, &img_height);
	map->digits.nine = mlx_xpm_file_to_image(map->mlx, "img/9.xpm",
			&img_width, &img_height);
}
