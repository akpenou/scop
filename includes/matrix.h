#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <stdio.h>

#define uint unsigned int

typedef struct		s_ivec4
{
	int				x;
	int				y;
	int				z;
	int				w;
}					t_ivec4;

typedef struct		s_vec4
{
	float			x;
	float			y;
	float			z;
	float			w;
}					t_vec4;

typedef struct		s_ivec3
{
	int				x;
	int				y;
	int				z;
}					t_ivec3;

typedef struct		s_vec3
{
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_matrix
{
	float			*data;
	unsigned int	ncols;
	unsigned int	nrows;
}					t_matrix;

t_matrix	*matrix_create(uint ncols, uint nrows);
t_matrix	*matrix_mult(t_matrix a, t_matrix b);
t_matrix	*matrix_add(t_matrix a, t_matrix b);
t_matrix	*matrix_id(uint size);

t_ivec4		ivec4_create(int x, int y, int z, int w);

void		matrix_print(t_matrix matrix);

uint		mpos(t_matrix matrix, uint x, uint y);

#endif
