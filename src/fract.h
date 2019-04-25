/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:24:14 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:24:17 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <fcntl.h>
# include <math.h>
# include <pthread.h>
# include <time.h>

# define WIND_X 800
# define WIND_Y 800

# define KEY_ESC 53
# define KEY_UP_ARROW 126
# define KEY_DOWN_ARROW 125
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124
# define KEY_N 45
# define KEY_F 3
# define KEY_W 13
# define KEY_E 14
# define KEY_R 15
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_H 4
# define KEY_MIN 27
# define KEY_PLUS 24
# define KEY_ONE 18
# define KEY_TWO 19
# define KEY_THREE 20
# define BODY_COUNT 2
# define THREAD_COUNT 8

typedef unsigned int	t_color;

typedef struct			s_mlx
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
	int		mode;
	int		iter_amount;
	int		help;
	int		flame_rot;
	int		flame_sample;
	int		flame_rand;
	double	flame_zoom;
	int		flame_funct;
	double	flame_x_shift;
	double	flame_y_shift;
	t_color	color;
}						t_mlx;

typedef struct			s_par
{
	t_mlx	*mlx;
	int		mod;
	double	(*funct)(double, double, t_mlx *);
}						t_par;

typedef union
{
	unsigned int		counter;
	float				normal;
}						t_hitcount;

typedef struct			s_pix
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	t_hitcount		value;
}						t_pix;

typedef struct			s_coeff
{
	double			ac;
	double			bc;
	double			cc;
	double			dc;
	double			ec;
	double			fc;
	double			pa1;
	double			pa2;
	double			pa3;
	double			pa4;
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}						t_coeff;

typedef struct			s_flame
{
	t_pix			**pixels;
	t_coeff			*array_coeff;
	int				num_eq;
	int				iteration;
	int				samples;
	double			xmin;
	double			xmax;
	double			ymin;
	double			ymax;
	double			x_shift;
	double			y_shift;
	int				rot;
	int				funct;
	pthread_mutex_t	*lock;

}						t_flame;

void					draw_update(t_mlx *mlx);
void					reset(t_mlx *mlx);
void					destroy(t_mlx *mlx);
void					color_shift(t_mlx *mlx);
void					xy_shift(char type, t_mlx *mlx);
int						key_press(int keycode, void *param);
void					update_img(t_mlx *mlx, int x, int y, t_color color);
int						closes(void *param);
unsigned int			set_color(t_mlx *mlx, double iter);
unsigned int			color_smooth(t_mlx *mlx, double iter);
unsigned int			color_crazy(t_mlx *mlx, double iter);
int						mouse_move(int x, int y, void *param);
int						mouse_press(int button, int x, int y, void *param);
void					draw_flame(t_mlx *mlx);
void					help_screen(t_mlx *mlx);
t_color					color_smooth(t_mlx *mlx, double iter);
t_color					color_crazy(t_mlx *mlx, double iter);
double					shift_xcoord(double x, t_mlx *mlx);
double					shift_ycoord(double y, t_mlx *mlx);
void					mode_shift(t_mlx *mlx, int type);
void					change_iter(char increase, t_mlx *mlx);
void					help_set(t_mlx *mlx);
void					flame_iter(t_mlx *mlx, int flag);
void					flame_rot(t_mlx *mlx, int flag);
void					newframe(t_mlx *mlx);
void					change_flame(t_mlx *mlx);

#endif
