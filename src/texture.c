/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:55:12 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/11 23:35:54 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <texture.h>

void	load_texture(t_texture texture, t_infos infos)
{
	GLuint	texture_idx;
	int		tex_loc;
	int		err;

	glGenTextures(1, &texture_idx);
	glBindTexture(GL_TEXTURE_2D, texture_idx);
	glActiveTexture(GL_TEXTURE0);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		exit(-1);
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width, texture.height, 0,
			GL_RGBA, GL_UNSIGNED_INT_8_8_8_8, texture.image.tab.ptr);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		exit(-1);
	}
	tex_loc = glGetUniformLocation (infos.shader_program, "basic_texture");
	glUseProgram (infos.shader_program);
	glUniform1i(tex_loc, 0);
	if ((err = glGetError()))
	{
		printf("GL %s, l: %d failed: %x\n", __func__, __LINE__, err);
		exit(-1);
	}
}
