/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trainingdrawing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gupatric <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 14:52:06 by gupatric          #+#    #+#             */
/*   Updated: 2021/02/05 15:59:45 by gupatric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "colors.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}			t_data;

void			my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*) dst = color;
}

int				main()
{
	void 	*mlx;
	void 	*win;
	t_data	img;
	int		i = 0;
	int		y;
	int		colors = 0x00FF0000;

	mlx = mlx_init();
	win = mlx_new_window(mlx, 1920, 1080, "Mlx train");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_length, &img.endian);
	my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
	while (i < 1080)
	{
		y = 0;
		while (y < 1920)
		{
			my_mlx_pixel_put(&img, y, i, colors);
			y++;
			cr = ft_get_r(colors);
			cb = ft_get_g(colors);
			cg = ft_get_b(colors);
			if ((unsigned char)cr > 255 
			colors = 
		}
		i++;
	}
	mlx_put_image_to_window(mlx, win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
