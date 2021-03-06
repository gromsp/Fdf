/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben	<marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:39:35 by pben              #+#    #+#             */
/*   Updated: 2019/03/04 14:58:17 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		**ft_initclr(int line, int len, int **clr) //тут был миша
{
	int i;

	i = 0;
	clr = (int**)malloc(line * sizeof(int*));
	while (i <= line)
	{
		clr[i] = (int*)malloc(len * sizeof(int));
		ft_bzero(clr[i], len);
		i++;
	}
	return (clr);
}

void	ft_graphics(int **mtx, int line_count, int len, t_pmtx *pmtx)//, int offset)
{

	t_img	*img;
	int		*addr;
	t_clr	*color;
	int 	offset = 85;
	
	
	
	if ((img = malloc(sizeof(t_img))) == NULL)
		exit(0);
	img->mlx_ptr = mlx_init();	
	//img->img = mlx_new_image(img->mlx_ptr, WINDOW, WINDOW);// картинки в окне
	img->win_ptr = mlx_new_window(img->mlx_ptr, 1000, 1000, "fdF"); //ширина, длина окна
	//img->addr = mlx_get_data_addr(img->img, &img->bts, &img->size_line, &img->endian);

	pmtx->img = img;
	color = malloc(sizeof(t_clr));
	pmtx->clr = ft_initclr(line_count, len, pmtx->clr); //тут был миша
	draw_map(line_count, len, pmtx, 16732240);

	char *string = "FDF by Pben"; 
	mlx_string_put (img->mlx_ptr, img->win_ptr, 1, 1, 0x0000ff00, string);

	mlx_hook(img->win_ptr, 17, 0, close_window, (void*)0);	
	mlx_hook(img->win_ptr, 2, 0, control, (void*)(pmtx));
	mlx_loop(img->mlx_ptr);	
	//free(img);
	//free(pmtx->mtx);
}

void	draw_map(int line_count, int len, t_pmtx *mtx, int color)
{ 
	int 		i;
	int			j;
	t_line		linex;
	t_line		liney;

	i = 0;
	while (i < line_count)
	{
		j = 0;
		while (j < len)
		{
			if (j < len - 1)
			{	
				linex = ft_create_line(mtx->mtx[i][j], mtx->mtx[i][j + 1]);
				if ((mtx->mtx[i][j]->z > 50 && mtx->flag == 0) || (mtx->clr[i][j] == 1)) //тут был миша
				{
				 	mtx->color = 16732240;
					mtx->clr[i][j] = 1;
				}
				else 
					mtx->color = 0x0000ff00;
				ft_put_line(mtx->img->mlx_ptr, mtx->img->win_ptr, linex, mtx->color, mtx->img->addr);	
			}
			if (i < line_count - 1)
			{
				liney = ft_create_line(mtx->mtx[i][j], mtx->mtx[i + 1][j]);
				if ((mtx->mtx[i][j]->z > 50 && mtx->flag == 0) || (mtx->clr[i][j] == 1)) //тут был миша
				{
				 	mtx->color = 16732240;
					mtx->clr[i][j] = 1;
				}
				else 
					mtx->color = 0x0000ff00;
				ft_put_line(mtx->img->mlx_ptr, mtx->img->win_ptr, liney, mtx->color, mtx->img->addr);		
			}		
			//mlx_put_image_to_window(mtx->img->mlx_ptr, mtx->img->win_ptr, mtx->img->img, 50, 50);// c какого пикселя вставлять в окно
			j++;	
		}
		i++;
		
	}
	mtx->flag = 1; //тут был миша
}
