/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akpenou <akpenou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/06 15:41:48 by akpenou           #+#    #+#             */
/*   Updated: 2017/04/08 18:49:07 by akpenou          ###   ########.fr       */
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

static t_infos	load_window(void)
{
	t_infos	infos;
	const GLubyte	*renderer;
	const GLubyte	*version;

	if (!(infos.window = SDL_CreateWindow("scop", SDL_WINDOWPOS_CENTERED,
					SDL_WINDOWPOS_CENTERED, WIN_WIDTH, WIN_HEIGTH,
					SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL)))
	{
		SDL_Quit();
		ft_error("SDL failed init");
	}
	if (!(infos.contexteOpenGL = SDL_GL_CreateContext(infos.window)))
	{
		printf("SDL_Init failed: %s\n", SDL_GetError());
		exit(-1);
	}
	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		ft_error("Glew error");
	renderer = glGetString(GL_RENDERER);
	version = glGetString(GL_VERSION);
	printf("Renderer: %s\n", renderer);
	printf("OpenGL version supported %s\n", version);
	return (infos);
}

t_infos				create_window(void)
{
	t_infos	infos;

	load_window_attribute();
	infos = load_window();
	return (infos);
}

void						destroy_window(t_infos infos)
{
	SDL_GL_DeleteContext(infos.contexteOpenGL);
	SDL_DestroyWindow(infos.window);
	SDL_Quit();
}

void						wait_event(t_infos infos, t_meta meta)
{
	int	terminer = 0;

	while(!terminer)
	{
		infos.elapsed_time = 1.0f;
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		draw(meta, infos);
		SDL_GL_SwapWindow(infos.window);
		SDL_WaitEvent(&infos.events);
		infos = move_cam(infos);
		if(infos.events.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
		if (infos.events.type == SDL_KEYDOWN)
			if (infos.events.key.keysym.sym == SDLK_q)
				terminer = 1;
	}
}
