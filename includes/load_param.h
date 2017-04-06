/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_param.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:13 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 19:19:40 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_PARAM_H
# define LOAD_PARAM_H

# include <GL/glew.h>
# include <SDL2/SDL.h>
# include <OpenGL/gl.h>
# include <parser.h>
# include <window.h>

# define NUM_BUFFERS 4

enum	e_vbo_index
{
	VERTEX_IDX,
	TEXTURE_IDX,
	NORMAL_IDX,
	INDEX_IDX
};

GLuint	load_vao(t_meta	meta);
void	draw(GLuint vao, t_meta meta, t_meta_system meta_system);

#endif
