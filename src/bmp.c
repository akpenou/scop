/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:15:53 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/10 20:13:04 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <bmp.h>

void		load_bmp(char *filename)
{
	t_bmp_infoheader	infoheader;
	t_bmp_header		header;
	FILE				*f;
	t_texture			*texture;

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
	printf("type %#hx\n", header.type);
	printf("offset %u\n", header.offset);
	printf("size %u\n", header.size);
	printf("height %u\n", infoheader.height);
	printf("width %u\n", infoheader.width);
	printf("planes %hu\n", infoheader.planes);
	printf("bits %hu\n", infoheader.bits);

}

int main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
	load_bmp(av[1]);
	return (0);
}
