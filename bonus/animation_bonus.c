#include "solong_bonus.h"

void	print_animated_crab(t_map *map)
{
	if (map->anim_flag == 1 && map->won == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.crab1,
			map->x * 50, map->y * 50);
	else if (map->anim_flag == 2 && map->won == 0)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.crab2,
			map->x * 50, map->y * 50);
}

void	print_animated_seaweed(t_map *map, int i, int j)
{
	if (map->map[i][j] == 'C' && map->anim_flag == 1)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.seaweed1,
			j * 50, i * 50);
	else if (map->map[i][j] == 'C' && map->anim_flag == 2)
		mlx_put_image_to_window(map->mlx, map->mlx_win, map->img.seaweed2,
			j * 50, i * 50);
}

int	animation(t_map *map)
{
	int	i;
	int	j;

	map->delay--;
	if (map->delay == 0)
	{
		print_animated_crab(map);
		i = 0;
		while (i < map->lines_num && map->c_left > 0)
		{
			j = 0;
			while (j < ft_strlen(map->map[0]))
			{
				print_animated_seaweed(map, i, j);
				j++;
			}
			i++;
		}
		if (map->anim_flag == 1)
			map->anim_flag = 2;
		else if (map->anim_flag == 2)
			map->anim_flag = 1;
		map->delay = 4000;
	}
	return (0);
}
