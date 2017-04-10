/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:15:53 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/10 22:54:19 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bmp.h>

static t_vec4		bgr_to_rgba(unsigned char blue, unsigned char green, unsigned char red)
{
	t_vec4	rgba;

	rgba = vec4_create((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, 1.0f);
	return (rgba);
}

static t_texture	read_image(t_texture texture, unsigned char *image)
{
	unsigned int	tmp_index;
	unsigned int	index;
	unsigned int	max;
	t_vec4			pixel;

	index = -1;
	max = texture.width * texture.height;
	texture.image = *array_create(0, VEC4);
	while (++index < max)
	{
		tmp_index = index * 3;
		// printf("pixel (%u, %u, %u)\n", image[tmp_index], image[tmp_index + 1], image[tmp_index + 2]);
		pixel = bgr_to_rgba(image[tmp_index], image[tmp_index + 1], image[tmp_index + 2]);
		array_pushback(&texture.image, (t_array_u)&pixel, 0);
	}
	return (texture);
}

t_texture			load_bmp(char *filename)
{
	t_bmp_infoheader	infoheader;
	t_bmp_header		header;
	t_texture			texture;
	unsigned char		*image;
	FILE				*f;

	f = fopen(filename, "rb");
 	if (fread(&header, sizeof(header), 1, f) < 1)
	{
		printf("Error: can't read the header of %s\n", filename);
		exit(-1);
	}
 	if (fread(&infoheader, sizeof(infoheader), 1, f) < 1)
	{
		printf("Error: can't read the infoheader of %s\n", filename);
		exit(-1);
	}
	texture.size = infoheader.width * infoheader.height * infoheader.bits / 8;
	if (!(image = (unsigned char *)malloc(texture.size)))
	{
		printf("Error: can't malloc\n");
		exit(-1);
	}
	texture.width = infoheader.width;
	texture.height = infoheader.height;
	texture.bits = infoheader.bits;
 	if (fread(image, texture.size, 1, f) < 1)
	{
		printf("Error: can't read the infoheader of %s\n", filename);
		exit(-1);
	}
	texture = read_image(texture, image);
	free(image);
	print_array(&texture.image, "texture");
	return (texture);
}
