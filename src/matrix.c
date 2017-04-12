/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 14:03:38 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:50:27 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

uint32_t	mpos(t_matrix matrix, uint32_t x, uint32_t y)
{
	if (x >= matrix.ncols || y >= matrix.nrows)
		perror("Wrong index");
	return (matrix.ncols * y + x);
}

void		matrix_print(t_matrix matrix)
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

void		matrix_free(t_matrix *matrix)
{
	free(matrix->data);
	free(matrix);
}

t_matrix	*matrix_create(uint32_t ncols, uint32_t nrows)
{
	t_matrix	*matrix;
	int			index;
	int			size;

	size = ncols * nrows;
	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		perror("Malloc error");
	if (!(matrix->data = (float *)malloc(sizeof(float) * size)))
		perror("Malloc error");
	index = -1;
	while (++index < size)
		matrix->data[index] = 0;
	matrix->ncols = ncols;
	matrix->nrows = nrows;
	return (matrix);
}

t_matrix	*matrix_id(uint32_t size)
{
	t_matrix	*matrix;
	uint32_t	index;

	matrix = matrix_create(size, size);
	index = -1;
	while (++index < size)
		matrix->data[mpos(*matrix, index, index)] = 1.0f;
	return (matrix);
}
