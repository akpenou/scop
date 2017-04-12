/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:47:05 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/12 11:47:41 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <GL/glew.h>
# include <SDL2/SDL.h>
# include <OpenGL/gl.h>
# include <stdio.h>
# include <error.h>
# include <parser.h>
# include <draw.h>
# include <texture.h>

# define WIN_HEIGTH 900
# define WIN_WIDTH 1600

typedef	struct		s_infos
{
	SDL_GLContext	contexte_opengl;
	SDL_Window		*window;
	SDL_Event		events;
	GLuint			shader_program;
	GLuint			vao;
	GLuint			proj_idx;
	GLuint			view_idx;
	GLuint			center_idx;
	GLuint			rot_idx;
	GLuint			fade_idx;
	t_matrix		*center;
	t_matrix		*translation;
	t_matrix		*rotation;
	t_matrix		*projection;
	t_matrix		*view;
	int				fade;
	float			current_fade;
	t_vec3			cam_pos;
	t_vec3			cam_rot;
	float			elapsed_time;
}					t_infos;

t_infos				create_window(void);
void				destroy_window(t_infos infos);
void				wait_event(t_infos infos, t_meta meta);

#endif
