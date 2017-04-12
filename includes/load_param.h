/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_param.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 17:05:13 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:52:37 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOAD_PARAM_H
# define LOAD_PARAM_H

# include <GL/glew.h>
# include <SDL2/SDL.h>
# include <OpenGL/gl.h>
# include <OpenGL/glu.h>
# include <parser.h>
# include <window.h>
# include <camera.h>
# include <matrix.h>

# define NUM_BUFFERS 2

typedef	struct s_infos	t_infos;

enum	e_vbo_index
{
	VERTEX_IDX,
	INDEX_IDX
};

GLuint	load_vao(t_meta	meta);
void	draw(t_meta meta, t_infos infos);

#endif
