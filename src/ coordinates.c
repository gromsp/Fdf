/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pben <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:31:08 by pben              #+#    #+#             */
/*   Updated: 2019/03/14 17:31:10 by pben             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    coordinates(int **mtx, t_point *f)
{
    int     i;
    int     j;

    i = 0;
    while (mtx[i])
    {
        j = 0;
        while(mtx[i][j])
        {
            if(mtx[i][j] == 0)
            {
                f->x = j;
                f->y = i;
            }
            else
                f->z = mtx[i][j];
        } 
    }
}

