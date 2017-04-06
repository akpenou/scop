/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:41:48 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/06 16:17:43 by akpenou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <window.h>

static void				load_window_attribute(void)
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		ft_error("SDL failed init");
	}
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);
}

static t_meta_system	load_window(void)
{
	t_meta_system	meta_system;
	const GLubyte	*renderer;
	const GLubyte	*version;

	if (!(meta_system.window = SDL_CreateWindow("scop", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGTH,
			SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)))
	{
		SDL_Quit();
		ft_error("SDL failed init");
	}
	if (!(meta_system.contexteOpenGL = SDL_GL_CreateContext(fenetre)))
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(-1);
	}
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		ft_error("Glew error");
	renderer = glGetString (GL_RENDERER);
	version = glGetString (GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	return (meta_system);
}

t_meta_system				create_window(void)
{
	t_meta_system	meta_system;

	load_window_attribute();
	meta_system = load_window();
	return (meta_system)
}

void						destroy_window(t_meta_system meta_system)
{
	SDL_GL_DeleteContext(meta_system.contexteOpenGL);
	SDL_DestroyWindow(meta_system.window);
	SDL_Quit();
}
