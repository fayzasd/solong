#include "mlx/mlx.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


int	main(void)
{
	void	*mlx;
    void    *mlx_win;
	void	*img;
	char	*relative_path = "./knight_png1640200642.xpm";
	int		img_width;
	int		img_height;
    t_data  image;


	mlx = mlx_init();
    mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	image.img = mlx_new_image(mlx, 1920, 1080);
	image.addr = mlx_get_data_addr(image.img, &image.bits_per_pixel, &image.line_length,
								&image.endian);
	img = mlx_xpm_file_to_image(mlx, relative_path, &img_width, &img_height);
    mlx_put_image_to_window(mlx, mlx_win, img, 0, 0);
    mlx_loop(mlx);
}