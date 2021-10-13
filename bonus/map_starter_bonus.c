#include "solong_bonus.h"

void	count_lines(t_map *map)
{
	int	i;

	i = 0;
	map->lines_num = 0;
	while (map->buff[i] != '\0')
	{
		if (map->buff[i] == '\n')
			map->lines_num++;
		i++;
	}
	if (i > 0 && map->buff[i - 1] != '\n')
		map->lines_num++;
}

int	get_file_length(char *str, t_map *map)
{
	int		fd;
	int		read_ret;
	char	buff[1024];
	int		file_length;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		errors("open()", map);
	file_length = 0;
	read_ret = read(fd, buff, sizeof(buff));
	while (read_ret != 0)
	{
		if (read_ret < 0)
		{
			close(fd);
			errors("read()", map);
		}
		file_length = file_length + read_ret;
		read_ret = read(fd, buff, sizeof(buff));
	}
	close(fd);
	return (file_length);
}

void	check_fd_and_get_buff(char *str, t_map *map)
{
	int	file_length;
	int	fd;
	int	read_ret;

	if (str[ft_strlen(str) - 1] != 'r' || str[ft_strlen(str) - 2] != 'e'
		|| str[ft_strlen(str) - 3] != 'b' || str[ft_strlen(str) - 4] != '.')
		errors("File with .ber extension is missing\n", map);
	file_length = get_file_length(str, map);
	map->buff = (char *)malloc(sizeof(char) * (file_length + 1));
	if (map->buff == NULL)
		errors("malloc(): Memory error\n", map);
	map->buff[file_length] = '\0';
	fd = open(str, O_RDONLY);
	if (fd < 0)
		errors("open()", map);
	read_ret = read(fd, map->buff, file_length);
	if (read_ret < 0)
	{
		close(fd);
		errors("read()", map);
	}
	close(fd);
	count_lines(map);
}

void	map_maker(t_map *map)
{
	int	i;
	int	j;
	int	x;
	int	k;

	i = 0;
	j = 0;
	while (j < map->lines_num)
	{
		x = i;
		while (map->buff[i] != '\n' && map->buff[i] != '\0')
			i++;
		map->map[j] = (char *)malloc(sizeof(char) * (i - x + 1));
		if (map->map[j] == NULL)
			errors("malloc(): Memory error\n", map);
		k = 0;
		while (x < i)
			map->map[j][k++] = map->buff[x++];
		map->map[j++][k] = '\0';
		i++;
	}
}

void	map_starter(t_map *map, char *argv)
{
	check_fd_and_get_buff(argv, map);
	map->map = (char **)malloc(sizeof(char *) * map->lines_num);
	if (map->map == NULL)
		errors("malloc(): Memory error\n", map);
	null_map(map);
	map_maker(map);
	if (map->lines_num < 3 || check_rectangular(map) == -1
		|| check_walls(map) == -1 || check_symbols(map) == -1)
		errors(0, map);
	get_crab_xy_and_c_left(map);
}
