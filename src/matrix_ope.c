/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_ope.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 11:49:55 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:50:27 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <matrix.h>

t_matrix	*matrix_add(t_matrix a, t_matrix b)
{
	t_matrix	*matrix;
	uint32_t	index;
	uint32_t	len;

	if (a.ncols != b.ncols || a.nrows != b.nrows)
		ft_error("matrix are not in good format for addition");
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
		ft_error("matrix are not in good format for multiplication");
	matrix = matrix_create(b.ncols, a.nrows);
	pos = ivec4_create(-1, -1, -1, -1);
	while ((unsigned int)++pos.x < b.ncols)
	{
		pos.y = -1;
		while ((unsigned int)++pos.y < a.nrows)
		{
			tmp = 0;
			tmp_pos = ivec4_create(-1, -1, -1, -1);
			while ((unsigned int)++tmp_pos.x < a.ncols &&
											(unsigned int)++tmp_pos.y < b.nrows)
				tmp += a.data[mpos(a, tmp_pos.x, pos.y)] *
											b.data[mpos(b, pos.x, tmp_pos.y)];
			matrix->data[mpos(*matrix, pos.x, pos.y)] = tmp;
		}
	}
	return (matrix);
}
