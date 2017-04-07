/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:47:05 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/07 10:39:36 by akpenou          ###   ########.fr       */
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

# define WIN_HEIGTH 600
# define WIN_WIDTH 800

typedef struct		s_meta_system
{
	SDL_GLContext	contexteOpenGL;
	SDL_Window*		window;
	SDL_Event		events;
	GLuint			shader_program;
	GLuint			vao;
}					t_meta_system;

t_meta_system		create_window(void);
void				destroy_window(t_meta_system meta_system);
void				wait_event(t_meta_system meta_system, t_meta meta);
void				draw(t_meta meta, t_meta_system meta_system);

#endif
