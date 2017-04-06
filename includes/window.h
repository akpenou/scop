/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:47:05 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 16:15:30 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include <SDL2/SDL.h>
# include <GL/glew.h>
# include <OpenGL/gl.h>
# include <stdio.h>
# include <error.h>

# define WIN_HEIGTH 600
# define WIN_WIDTH 800

typedef struct		s_meta_system
{
	SDL_GLContext	contexteOpenGL;
	SDL_Window*		window;
	SDL_Event		events;
}					t_meta_system;

t_meta_system		create_window(void);
void				destroy_window(t_meta_system meta_system);

#endif
