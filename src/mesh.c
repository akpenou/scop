/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 18:26:42 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/07 12:25:44 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mesh.h>

static char		*load_file(char *filename)
{
	FILE	*file;
	char	buffer[300];
	char	*text;
	int		ret;
	int		len;

	len = 0;
	text = NULL;
	if (!(file = fopen(filename, "r")))
		ft_error("Open error");
	while ((ret = fread(buffer, 1, 300, file)))
	{
		text = realloc(text, len + ret + 1);
		memcpy(text + len, buffer, ret);
		len += ret;
	}
	text[len] = 0;
	return (text);
}

static GLuint	load_shader(GLenum shader_type, char *filename)
{
	GLuint	shader;
	char	*shader_code;

	
	shader = glCreateShader(shader_type);
	shader_code = load_file(filename);
	glShaderSource(shader, 1, (const GLchar *const *)&shader_code, NULL);
	glCompileShader(shader);
	//free(shader_code);
	if (SDL_GetError()[0])
		printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	if (glGetError())
		printf("GL %s, l: %d failed: %#x\n", __func__, __LINE__, glGetError());
	return (shader);
}

GLuint			load_shader_program(void)
{
	GLuint	shader_program;

	shader_program = glCreateProgram();
	glAttachShader(shader_program, load_shader(GL_VERTEX_SHADER, "shader.vs"));
	glAttachShader(shader_program, load_shader(GL_FRAGMENT_SHADER, "shader.fs"));
	glLinkProgram (shader_program);
	if (SDL_GetError()[0])
		printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	if (glGetError())
		printf("GL %s, l: %d failed: %#x\n", __func__, __LINE__, glGetError());
	return (shader_program);
}
