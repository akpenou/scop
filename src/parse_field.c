/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_vertex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/05 14:39:54 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 15:37:07 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <parser.h>

t_array		*parse_vertex(char *input, t_array *array)
{
	t_vec4	res;
	char	dash[10];

	res.w = 1.0f;
	if (!(sscanf(input, "%s %f %f %f", dash, &res.x, &res.y, &res.z) ||
		sscanf(input, "%s %f %f %f %f", dash, &res.x, &res.y, &res.z, &res.w)))
		ft_error("sscanf error");
	// printf("v  [ %5.2f, %5.2f, %5.2f, (%5.2f)]\n", res.x, res.y, res.z, res.w);
	return (array_pushback(array, (t_array_u)&res, 0));
}

t_array		*parse_textures(char *s, t_array *array)
{
	t_vec3	res;
	char	dash[10];

	res.z = 0.0f;
	if (!(sscanf(s, "%s %f %f", dash, &res.x, &res.y) ||
				sscanf(s, "%s %f %f %f", dash, &res.x, &res.y, &res.z)))
		ft_error("sscanf error");
	// printf("vt [ %5.2f, %5.2f, (%5.2f)]\n", res.x, res.y, res.z);
	return (array_pushback(array, (t_array_u)&res, 0));
}

t_array		*parse_normals(char *s, t_array *array)
{
	t_vec3	res;
	char	dash[10];

	res.z = 0.0f;
	if (!(sscanf(s, "%s %f %f %f", dash, &res.x, &res.y, &res.z)))
		ft_error("sscanf error");
	// printf("vn [ %5.2f, %5.2f, %5.2f]\n", res.x, res.y, res.z);
	return (array_pushback(array, (t_array_u)&res, 0));
}

t_array		*parse_faces(char *input, t_array *array)
{
	t_ivec3	p;
	char	dash[10];
	int		i;
	char	*input_end;

	input_end = strlen(input) + input;
	if (!(sscanf(input, "%s %d %d %n", dash, &p.x, &p.y, &i) && (input += i)))
		ft_error("sscanf error");
	while (input < input_end)
	{
		if (sscanf(input, "%d %n", &p.z, &i) && (input += i))
			array_pushback(array, (t_array_u)&p, 0);
		// else if (sscanf("%f/%f ", res->p[i].x, res->p[i].y))
		// 	res->p[i].w = 0b011;
		// else if (sscanf("%f/%f/%f ", res->p[i].x, res->p[i].y, res->p[i].z))
		// 	res->p[i].w = 0b111;
		// else if (sscanf("%f//%f ", res->p[i].x, res->p[i].z))
		// 	res->p[i].w = 0b101;
		else
			break ;
		// printf("f  [ %5d, %5d, %5d]\n", p.x, p.y, p.z);
		p.y = p.z;
	}
	return (array);
}
