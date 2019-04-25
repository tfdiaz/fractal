/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_modes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdiaz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/24 15:32:48 by tdiaz             #+#    #+#             */
/*   Updated: 2019/04/24 15:32:51 by tdiaz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Following functions create the two color modes for julia and mandelbrot
** fractals. Crazy color was accidental. It was an attempt to mix two colors
** from a pallette but ended up creating distinct colors for very little change
** in input. Smooth color relies on transfering hsv to rgb.
*/

#include "../fract.h"

static t_color	new_color(t_color col1, t_color col2, double shift)
{
	t_color	r_new;
	t_color	g_new;
	t_color	b_new;
	t_color	move;

	r_new = col1 & (0xff << 16);
	g_new = col1 & (0xff << 8);
	b_new = col1 & 0xff;
	move = (r_new - (col2 & (0xff << 16))) * shift;
	r_new += move % 0xff;
	move = (g_new - (col2 & (0xff << 8))) * shift;
	g_new += move % 0xff;
	move = (b_new - (col2 & 0xff)) * shift;
	b_new += move % 0xff;
	r_new <<= 16;
	g_new <<= 8;
	return (r_new + g_new + b_new);
}

t_color			color_crazy(t_mlx *mlx, double iter)
{
	int				n;
	t_color			col1;
	t_color			col2;
	const t_color	palette[] = {0x594157,
						0x7E7AAF, 0x7D8CC4, 0xA0D2DB, 0xBEE7E8};

	col1 = palette[(t_color)floor(iter) % 5];
	col2 = palette[((t_color)floor(iter) + 1) % 5];
	return (mlx_get_color_value(mlx->mlx_ptr,
			new_color(col1, col2, frexp(iter, &n))));
}

static t_color	make_rgb(double r, double g, double b)
{
	t_color	r_new;
	t_color	g_new;
	t_color	b_new;

	r *= 0xff;
	g *= 0xff;
	b *= 0xff;
	r_new = (t_color)floor(r) << 16;
	g_new = (t_color)floor(g) << 8;
	b_new = (t_color)floor(b);
	return (r_new + g_new + b_new);
}

static t_color	rgb_from_hsv(double h, double s, double v)
{
	double	c;
	double	x;
	double	m;
	t_color	color;

	c = v * s;
	x = c * (1.0 - fabs(fmod(h / 60.0, 2) - 1.0));
	m = v - c;
	if (h >= 0.0 && h < 60.0)
		color = make_rgb(c + m, x + m, m);
	else if (h >= 60.0 && h < 120.0)
		color = make_rgb(x + m, c + m, m);
	else if (h >= 120.0 && h < 180.0)
		color = make_rgb(m, c + m, x + m);
	else if (h >= 180.0 && h < 240.0)
		color = make_rgb(m, x + m, c + m);
	else if (h >= 240.0 && h < 300.0)
		color = make_rgb(x + m, m, c + m);
	else if (h >= 300.0 && h < 360.0)
		color = make_rgb(c + m, m, x + m);
	else
		color = make_rgb(m, m, m);
	return (color);
}

t_color			color_smooth(t_mlx *mlx, double iter)
{
	t_color color;

	color = rgb_from_hsv(190.0 * (iter / (double)mlx->iter_amount),
			0.6f, .8f);
	return (mlx_get_color_value(mlx->mlx_ptr, color));
}
