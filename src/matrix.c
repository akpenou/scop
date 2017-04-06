/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:03:38 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 11:12:31 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_ivec4	ivec4_create(int x, int y, int z, int w)
{
	t_ivec4		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;

	return (vec);
}

t_vec4	vec4_create(float x, float y, float z, float w)
{
	t_vec4		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;
	vec.w = w;

	return (vec);
}

t_ivec3	ivec3_create(int x, int y, int z)
{
	t_ivec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;

	return (vec);
}

t_vec3	vec3_create(float x, float y, float z)
{
	t_vec3		vec;

	vec.x = x;
	vec.y = y;
	vec.z = z;

	return (vec);
}

uint	mpos(t_matrix matrix, uint x, uint y)
{
	if (x >= matrix.ncols || y >= matrix.nrows)
		perror("Wrong index");
	return (matrix.ncols * y + x);
}

void	matrix_print(t_matrix matrix)
{
	t_ivec4		pos;

	pos = ivec4_create(-1, -1, -1, -1);
	printf("matrix %dx%d\n", matrix.ncols, matrix.nrows);
	while ((unsigned int)++pos.y < matrix.nrows)
	{
		printf("[");
		pos.x = -1;
		while ((unsigned int)++pos.x < matrix.ncols)
			printf("% 8.2f,", matrix.data[mpos(matrix, pos.x, pos.y)]);
		printf(" ]\n");
	}
}

t_matrix	*matrix_create(uint ncols, uint nrows)
{
	t_matrix	*matrix;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		perror("Malloc error");
	if (!(matrix->data = (float *)malloc(sizeof(float) * ncols * nrows)))
		perror("Malloc error");
	matrix->ncols = ncols;
	matrix->nrows = nrows;
	return (matrix);
}

t_matrix	*matrix_id(uint size)
{
	t_matrix	*matrix;
	uint		index;

	matrix = matrix_create(size, size);
	index = -1;
	while (++index < size)
		matrix->data[mpos(*matrix, index, index)] = 1.0f;
	return (matrix);
}

t_matrix	*matrix_add(t_matrix a, t_matrix b)
{
	t_matrix		*matrix;
	uint	index;
	uint	len;

	if (a.ncols != b.ncols || a.nrows != b.nrows)
		return (NULL);
	len = a.ncols * a.nrows;
	index = -1;
	matrix = matrix_create(a.ncols, a.nrows);
	while (++index < len)
		matrix->data[index] = a.data[index] + b.data[index];
	return (matrix);
}

t_matrix	*matrix_mult(t_matrix a, t_matrix b)
{
	t_matrix	*matrix;
	t_ivec4		tmp_pos;
	t_ivec4		pos;
	float		tmp;
	
	if (a.ncols != b.nrows)
		return (NULL);
	matrix = matrix_create(b.ncols, a.nrows);
	pos = ivec4_create(-1, -1, -1, -1);
	while ((unsigned int)++pos.x < b.ncols)
	{
		pos.y = -1;
		while ((unsigned int)++pos.y < a.nrows)
		{
			tmp = 0;
			tmp_pos = ivec4_create(-1, -1, -1, -1);
			while ((unsigned int)++tmp_pos.x < a.ncols && (unsigned int)++tmp_pos.y < b.nrows)
				tmp += a.data[mpos(a, tmp_pos.x, pos.y)] * b.data[mpos(b, pos.x, tmp_pos.y)];
			matrix->data[mpos(*matrix, pos.x, pos.y)] = tmp;
		}
	}
	return (matrix);
}

/*
** int	main()
** {
** 	t_matrix	*matrix;
** 
** 	matrix = matrix_create(3, 3);
** 	matrix->data[mpos(*matrix, 0, 0)] = 00;
** 	matrix->data[mpos(*matrix, 1, 0)] = 10;
** 	matrix->data[mpos(*matrix, 2, 0)] = 20;
** 	matrix->data[mpos(*matrix, 0, 1)] = 01;
** 	matrix->data[mpos(*matrix, 1, 1)] = 11;
** 	matrix->data[mpos(*matrix, 2, 1)] = 21;
** 	matrix->data[mpos(*matrix, 0, 2)] = 02;
** 	matrix->data[mpos(*matrix, 1, 2)] = 12;
** 	matrix->data[mpos(*matrix, 2, 2)] = 22;
** 
** 	matrix_print(*matrix);
** 	matrix = matrix_mult(*matrix, *matrix);
** 	matrix_print(*matrix);
** 	matrix = matrix_add(*matrix, *matrix_id(3));
** 	matrix_print(*matrix);
** 	return (0);
** }
*/
