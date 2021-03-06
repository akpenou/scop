/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:04:38 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:08:45 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include <stdlib.h>
# include <stdio.h>
# include <error.h>

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

t_matrix			*matrix_create(uint32_t ncols, uint32_t nrows);
t_matrix			*matrix_mult(t_matrix a, t_matrix b);
t_matrix			*matrix_add(t_matrix a, t_matrix b);
t_matrix			*matrix_id(uint32_t size);

t_ivec4				ivec4_create(int x, int y, int z, int w);
t_vec4				vec4_create(float x, float y, float z, float w);
t_ivec3				ivec3_create(int x, int y, int z);
t_vec3				vec3_create(float x, float y, float z);

void				matrix_print(t_matrix matrix);
void				matrix_free(t_matrix *matrix);

uint32_t			mpos(t_matrix matrix, uint32_t x, uint32_t y);

#endif
