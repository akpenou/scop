/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:41:50 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:03:00 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <load_param.h>

GLuint	load_vao(t_meta meta)
{
	GLuint	vao;
	GLuint	err;
	GLuint	vbo[NUM_BUFFERS];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(NUM_BUFFERS, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[VERTEX_IDX]);
	glBufferData(GL_ARRAY_BUFFER, meta.vertex->size, meta.vertex->tab.ptr,
																GL_STATIC_DRAW);
	glEnableVertexAttribArray(VERTEX_IDX);
	glVertexAttribPointer(VERTEX_IDX, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[INDEX_IDX]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, meta.face->size, meta.face->tab.ivec3,
																GL_STATIC_DRAW);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		ft_error("");
	}
	return (vao);
}
