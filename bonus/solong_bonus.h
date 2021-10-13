#ifndef SOLONG_BONUS_H

# define SOLONG_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <mlx.h>

typedef struct s_img
{
	void	*crab1;
	void	*seaweed1;
	void	*crab2;
	void	*seaweed2;
	void	*cave;
	void	*starfish;
	void	*back;
}
t_img;

typedef struct s_digits
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
	int		x;
}
t_digits;

typedef struct s_map
{
	char		chars[6];
	char		*buff;
	char		**map;
	int			lines_num;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
	int			moves;
	int			c_left;
	int			won;
	t_img		img;
	void		*mlx;
	void		*mlx_win;
	int			anim_flag;
	int			delay;
	t_digits	digits;
}
t_map;

int		ft_strlen(char *str);
void	errors(char *error, t_map *map);
void	ft_free(t_map *map);
void	fill_struct(t_map *map);
void	null_map(t_map *map);

void	count_lines(t_map *map);
int		get_file_length(char *str, t_map *map);
void	check_fd_and_get_buff(char *str, t_map *map);
void	map_maker(t_map *map);
void	map_starter(t_map *map, char *argv);

int		check_rectangular(t_map *map);
int		check_walls(t_map *map);
int		check_symbols(t_map *map);
void	get_crab_xy_and_c_left(t_map *map);

void	create_imgs(t_map *map);
void	print_frame(t_map *map);
void	choose_image(t_map *map, int y, int x, char symbol);

int		key_hook(int key, t_map *map);
int		win_close(int keycode, t_map *map);
void	print_crab(int keycode, t_map *map);
void	ft_putnbr_to_window(int n, t_map *map);
void	digit_chooser(int n, t_map *map, int x);

int		animation(t_map *map);
void	print_animated_crab(t_map *map);
void	print_animated_seaweed(t_map *map, int i, int j);

void	create_digits(t_map *map);
void	create_digits_xpm(t_map *map);

#endif
