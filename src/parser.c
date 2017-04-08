/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:32:10 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/08 23:10:59 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>
t_vec3		find_center(t_meta meta)
{
	t_vec4		min;
	t_vec4		max;
	t_vec3		center;
	uint32_t	index;

	index = 0;
	min = meta.vertex->tab.vec4[index];
	max = meta.vertex->tab.vec4[index];
	while (++index < meta.vertex->nb_elem)
	{
		if (min.x > meta.vertex->tab.vec4[index].x)
			min.x = meta.vertex->tab.vec4[index].x;
		if (max.x < meta.vertex->tab.vec4[index].x)
			max.x = meta.vertex->tab.vec4[index].x;
		if (min.y > meta.vertex->tab.vec4[index].y)
			min.y = meta.vertex->tab.vec4[index].y;
		if (max.y < meta.vertex->tab.vec4[index].y)
			max.y = meta.vertex->tab.vec4[index].y;
		if (min.z > meta.vertex->tab.vec4[index].z)
			min.z = meta.vertex->tab.vec4[index].z;
		if (max.z < meta.vertex->tab.vec4[index].z)
			max.z = meta.vertex->tab.vec4[index].z;
		center = vec3_create(-(max.x + min.x) / 2, -(max.y + min.y) / 2, -(max.z + min.z) / 2);
	printf("center (%f, %f, %f)\n", center.x, center.y, center.z);
	}
	printf("center (%f, %f, %f)\n", center.x, center.y, center.z);
	return (center);
}

t_meta		init_meta(void)
{
	t_meta	meta;


	meta.vertex = array_create(0, VEC4);
	meta.normal = array_create(0, VEC3);
	meta.texture = array_create(0, VEC3);
	meta.face = array_create(0, IVEC3);
	return (meta);
}

void		print_meta(t_meta meta)
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
	meta.center = find_center(meta);
	return (meta);
}

