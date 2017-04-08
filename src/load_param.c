/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:41:50 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/08 10:45:52 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <load_param.h>

GLuint	load_vao(t_meta	meta)
{
	GLuint	vao;
	GLuint	err;
	GLuint	vbo[NUM_BUFFERS];

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glGenBuffers(NUM_BUFFERS, vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[VERTEX_IDX]);
	glBufferData(GL_ARRAY_BUFFER, meta.vertex->size, meta.vertex->tab.ptr, GL_STATIC_DRAW);
	glEnableVertexAttribArray(VERTEX_IDX);
	glVertexAttribPointer(VERTEX_IDX, 4, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[TEXTURE_IDX]);
	glBufferData(GL_ARRAY_BUFFER, meta.texture->size, meta.texture->tab.ptr, GL_STATIC_DRAW);
	glEnableVertexAttribArray(TEXTURE_IDX);
	glVertexAttribPointer(TEXTURE_IDX, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[NORMAL_IDX]);
	glBufferData(GL_ARRAY_BUFFER, meta.normal->size, meta.normal->tab.ptr, GL_STATIC_DRAW);
	glEnableVertexAttribArray(NORMAL_IDX);
	glVertexAttribPointer(NORMAL_IDX, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo[INDEX_IDX]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, meta.face->size, meta.face->tab.ivec3, GL_STATIC_DRAW);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		ft_error("");
	}
	return (vao);
}

/*
** void	loop_gl(t_meta meta, t_infos infos, GLuint vao)
** {
** 	float speed = 1.0f; // move at 1 unit per second 
** 	float last_position = 0.0f;
** 
** 	double previous_time = SDL_GetTicks();
** 	double current_time = SDL_GetTicks();
** 	double elapsed_time = current_time - previous_time / 1000;
** 	int matrix_location = glGetUniformLocation (shader_programme, "matrix");
** 
** 	while (!terminer)
** 	{
** 		current_time = SDL_GetTicks();
** 		elapsed_time = (current_time - previous_time) / 1000;
** 		previous_time = current_time;
** 
** 		glUseProgram (shader_programme);
** 		glUniformMatrix4fv(matrix_location, 1, GL_FALSE, matrix);
** 
** 		// Clear the window
** 		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
** 			glUseProgram (shader_programme);
** 			glBindVertexArray (vao);
** 			// draw points 0-3 from the currently bound VAO with current in-use shader
** 			glDrawArrays (GL_TRIANGLES, 0, 3);
** 		// Update the window
** 		SDL_PollEvent(&evenements);
** 		SDL_GL_SwapWindow(fenetre);
** 		// SDL_WaitEvent(&evenements);
** 		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
** 			terminer = 1;
** 	}
** }
*/
