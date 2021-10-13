#include "solong_bonus.h"

void	errors(char *error, t_map *map)
{
	write(2, "Error\n", 6);
	if (errno != 0)
		perror(error);
	else if (error == 0)
	{
		write(2, "Invalid map\n1. The map must be composed of only ", 48);
		write(2, "5 characters: 0, 1, C, E, P.\n2. The map must be ", 48);
		write(2, "surrounded by walls.\n3. The map must have at least ", 51);
		write(2, "one exit, one collectible, and one starting position.\n", 54);
		write(2, "4. The map must be rectangular.\n", 32);
	}
	else
		write(2, error, ft_strlen(error));
	ft_free(map);
	exit(-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_free(t_map *map)
{
	int	i;

	if (map->buff)
		free(map->buff);
	i = 0;
	if (map->map)
	{
		while (i < map->lines_num)
		{
			if (map->map[i])
				free(map->map[i]);
			i++;
		}
		free(map->map);
	}
}

void	fill_struct(t_map *map)
{
	map->lines_num = 0;
	map->buff = NULL;
	map->map = NULL;
	map->moves = 0;
	map->c_left = 0;
	map->won = 0;
	map->chars[0] = '1';
	map->chars[1] = '0';
	map->chars[2] = '0';
	map->chars[3] = '0';
	map->chars[4] = '0';
	map->chars[5] = '\0';
	map->anim_flag = 1;
	map->delay = 4000;
	map->digits.x = 0;
}

void	null_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->lines_num)
	{
		map->map[i] = NULL;
		i++;
	}
}
