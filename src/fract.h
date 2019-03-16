
#ifndef FRACT_H
# define FRACT_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>

# define WIND_X 800
# define WIND_Y 800

# define KEY_ESC 53
# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_F 3
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_MIN 27
# define KEY_PLUS 24
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define BODY_COUNT 2
# define THREAD_COUNT 8

typedef unsigned int t_color;

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*image;
	char	*address;
	char	freeze;
	int		**data;
	int		bpp;
	int		sl;
	int		color_mode;
	double	con_x;
	double	con_y;
	double	x_shift;
	double	y_shift;
	int		org_x;
	int		org_y;
	double	zoom;
	int		mod;
	int		iter_amount;
	t_color	color;
}				t_mlx;

typedef struct	s_par
{
	t_mlx	*mlx;
	int		mod;
}				t_par;

void			draw_update(t_mlx *mlx);
// void			theta_shift(char type, t_mlx *mlx);
// void			phi_shift(char type, t_mlx *mlx);
// void			z_shift(char type, t_mlx *mlx);
// void			zoom_shift(char type, t_mlx *mlx);
// void			focal_shift(char type, t_mlx *mlx);
void			reset(t_mlx *mlx);
void			destroy(t_mlx *mlx);
void			color_shift(char type, t_mlx *mlx);
void			xy_shift(char type, t_mlx *mlx);
int				key_press(int keycode, void *param);
void			update_img(t_mlx *mlx, int x, int y, t_color);
int				closes(void *param);
unsigned int	set_color(t_mlx *mlx, int iter);
int				mouse_move(int x, int y, void *param);
int				mouse_press(int button, int x, int y, void *param);

#endif
