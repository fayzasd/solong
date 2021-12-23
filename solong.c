/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasad <fasad@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 12:14:02 by fasad             #+#    #+#             */
/*   Updated: 2021/12/22 23:29:41 by fasad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;


typedef struct s_vars{
	void	*mlx;
	void	*win;
	int		key_count;
}	t_vars;

typedef struct tystem_vars{
	int key_count;
}	system_vars;

// typedef struct i_stuff{
// 	void *img;
// 	char *relative_path;
// 	int img_width;
// 	int img_height;
// } img_stuff;

int key_hook(int kc, t_vars *vars)
{	
	if (kc == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else if(kc == 0 || kc == 1 || kc == 2 || kc == 13)
		vars->key_count++;	
	return 0;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(void)
{
	// t_data	img;
	t_vars	vars;
	void *image;
	char *relative_path = "./knight_png1640200642.xpm";
	int img_width = 50;
	int img_height = 50;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "So_long");
	//img.img = mlx_new_image(vars.mlx, 1920, 1080);
	//img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	image = mlx_xpm_file_to_image(vars.mlx, relative_path, &img_width, &img_height);
	mlx_put_image_to_window(vars.mlx, vars.win, image, 0, 0);
	mlx_key_hook(vars.win, key_hook, &vars);
	mlx_loop(vars.mlx);
}
