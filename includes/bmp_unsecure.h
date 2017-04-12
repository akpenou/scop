/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_unsecure.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 12:14:50 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 13:56:49 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_UNSECURE_H
# define BMP_UNSECURE_H

# include <stdio.h>
# include <stdlib.h>
# include <matrix.h>
# include <array.h>
# include <texture.h>
# include <error.h>

typedef struct s_texture	t_texture;

typedef struct	 			s_bmp_header
{
	unsigned short int		type;
	unsigned int			size;
	unsigned short int		reserved1;
	unsigned short int		reserved2;
	unsigned int			offset;
}							t_bmp_header;

typedef struct  			s_bmp_infoheader
{
	unsigned int			size;
	int						width;
	int						height;
	unsigned short int		planes;
	unsigned short int		bits;
	unsigned int			compression;
	unsigned int			imagesize;
	int						xresolution;
	int						yresolution;
	unsigned int			ncolours;
	unsigned int			importantcolours;
}							t_bmp_infoheader;

t_texture					load_bmp(char *filename);

#endif
