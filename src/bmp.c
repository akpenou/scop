/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:15:53 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 10:50:19 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bmp.h>

static unsigned int		bgr_to_rgba(unsigned char blue, unsigned char green,
															unsigned char red)
{
	unsigned int	rgba;
	unsigned char	*color;

	color = (unsigned char *)&rgba;
	color[3] = red;
	color[2] = green;
	color[1] = blue;
	color[0] = 255;
	return (rgba);
}

static t_texture		read_image(t_texture texture, unsigned char *image)
{
	unsigned int	tmp_index;
	unsigned int	index;
	unsigned int	max;
	unsigned int	pixel;

	index = -1;
	max = texture.width * texture.height;
	texture.image = *array_create(0, COLOR);
	while (++index < max)
	{
		tmp_index = index * 3;
		pixel = bgr_to_rgba(image[tmp_index], image[tmp_index + 1],
														image[tmp_index + 2]);
		array_pushback(&texture.image, (t_array_u)(&pixel), 0);
	}
	return (texture);
}

t_texture				load_bmp(char *filename)
{
	t_bmp_infoheader	infoheader;
	t_bmp_header		header;
	t_texture			texture;
	unsigned char		*image;
	FILE				*f;

	if (!(f = fopen(filename, "rb")))
		ft_error("Error: can't open ../textures/default.bmp");
	if ((fread(&header, sizeof(header), 1, f) < 1) ||
			(fread(&infoheader, sizeof(infoheader), 1, f) < 1))
		ft_error("Error: can't read the header of ../textures/default.bmp");
	if (header.type != 0x4d42 || infoheader.compression)
		ft_error("Wrong type of file magic or compression");
	texture.size = infoheader.width * infoheader.height * infoheader.bits / 8;
	if (!(image = (unsigned char *)malloc(texture.size)))
		ft_error("malloc error");
	texture.width = infoheader.width;
	texture.height = infoheader.height;
	texture.bits = infoheader.bits;
	if (fread(image, texture.size, 1, f) < 1)
		ft_error("Error: can't read the image of ../textures/default.bmp");
	texture = read_image(texture, image);
	free(image);
	fclose(f);
	return (texture);
}
