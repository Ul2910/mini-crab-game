#include "solong_bonus.h"

int	check_rectangular(t_map *map)
{
	int	i;
	int	line_length;

	line_length = ft_strlen(map->map[0]);
	if (line_length < 3)
		return (-1);
	i = 1;
	while (i < map->lines_num)
	{
		if (ft_strlen(map->map[i]) != line_length)
			return (-1);
		i++;
	}
	return (0);
}

int	check_walls(t_map *map)
{
	int	i;
	int	line_length;

	line_length = ft_strlen(map->map[0]);
	i = 0;
	while (i < map->lines_num)
	{
		if (map->map[i][0] != '1' || map->map[i][line_length - 1] != '1')
			return (-1);
		i++;
	}
	i = 0;
	while (i < line_length)
	{
		if (map->map[0][i] != '1' || map->map[map->lines_num - 1][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_symbols(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->lines_num - 1)
	{
		j = 0;
		while (j < ft_strlen(map->map[0]))
		{
			if (map->map[i][j] == 'P' && map->chars[2] == 'P')
				return (-1);
			else if (map->map[i][j] == 'P')
				map->chars[2] = 'P';
			else if (map->map[i][j] == 'E')
				map->chars[3] = 'E';
			else if (map->map[i][j] == 'C')
				map->chars[4] = 'C';
			else if (map->map[i][j] != '1' && map->map[i][j] != '0')
				return (-1);
			j++;
		}
	}
	if (map->chars[2] != 'P' || map->chars[3] != 'E' || map->chars[4] != 'C')
		return (-1);
	return (0);
}

void	get_crab_xy_and_c_left(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->lines_num - 1)
	{
		j = 0;
		while (j < ft_strlen(map->map[0]))
		{
			if (map->map[i][j] == 'P')
			{
				map->x = j;
				map->y = i;
			}
			else if (map->map[i][j] == 'C')
				map->c_left++;
			j++;
		}
	}
}
