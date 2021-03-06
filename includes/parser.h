/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:14:20 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:14:24 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <array.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <error.h>

typedef struct	s_meta
{
	t_array		*vertex;
	t_array		*normal;
	t_array		*texture;
	t_array		*face;
	t_vec3		center;
}				t_meta;

t_array			*parse_normals(char *s, t_array *array);
t_array			*parse_textures(char *s, t_array *array);
t_array			*parse_vertex(char *s, t_array *array);
t_array			*parse_faces(char *input, t_array *array);

t_meta			parser(char *filename);
t_meta			init_meta(void);
void			print_meta(t_meta meta);

#endif
