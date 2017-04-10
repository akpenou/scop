/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:15:56 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/10 20:13:26 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BMP_H
# define BMP_H

# include <stdio.h>
# include <stdlib.h>

typedef struct			__attribute__((__packed__)) 
{
	unsigned short int	type;  /* Magic identifier            */
	unsigned int		size;  /* File size in bytes          */
	unsigned short int	reserved1;
	unsigned short int	reserved2;
	unsigned int		offset; /* Offset to image data, bytes */
}						t_bmp_header;

typedef struct			__attribute__((__packed__))
{
	unsigned int		size;               /* Header size in bytes      */
	int					width;                /* Width and height of image */
	int					height;                /* Width and height of image */
	unsigned short int	planes;       /* Number of colour planes   */
	unsigned short int	bits;         /* Bits per pixel            */
	unsigned int		compression;        /* Compression type          */
	unsigned int		imagesize;          /* Image size in bytes       */
	int					xresolution;     /* Pixels per meter          */
	int					yresolution;     /* Pixels per meter          */
	unsigned int		ncolours;           /* Number of colours         */
	unsigned int		importantcolours;   /* Important colours         */
}						t_bmp_infoheader;

// define texture

#endif
