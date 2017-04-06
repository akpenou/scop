/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:32:10 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 16:14:20 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

static t_meta	init_meta(void)
{
	t_meta	meta;


	meta.vertex = array_create(0, VEC4);
	meta.normal = array_create(0, VEC3);
	meta.texture = array_create(0, VEC3);
	meta.face = array_create(0, IVEC3);
	return (meta);
}

static void		print_meta(t_meta meta)
{
	print_meta_array(meta.vertex, "vertex");
	print_meta_array(meta.normal, "normals");
	print_meta_array(meta.texture, "textures");
	print_meta_array(meta.face, "face");
}

t_meta		parser(char *filename)
{
	FILE	*f;
	char	line[200];
	t_meta	meta;

	meta = init_meta();
	if (!(f = fopen(filename, "r")))
		ft_error("Open error");
	while (fgets(line, 200, f))
	{
		if ((!strncmp(line, "v ", 2) && parse_vertex(line, meta.vertex)) ||
			(!strncmp(line, "vt ", 3) && parse_textures(line, meta.texture)) ||
			(!strncmp(line, "vn ", 3) && parse_normals(line, meta.normal)) ||
			(!strncmp(line, "f ", 2) && parse_faces(line, meta.face)))
			continue ;
	}
	return (meta);
}

