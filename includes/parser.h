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
}				t_meta;

t_array			*parse_normals(char *s, t_array *array);
t_array			*parse_textures(char *s, t_array *array);
t_array			*parse_vertex(char *s, t_array *array);
t_array			*parse_faces(char *input, t_array *array);

#endif
