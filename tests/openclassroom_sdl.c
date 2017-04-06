#include <stdio.h>
#include <SDL2/SDL.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>

/* dimensions de la fenetre */
#define W 640
#define H 480

/* initialise opengl */
void init_gl(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


int main(int argc, char **argv)
{
	int loop = 1;       /* booleen du 'main loop' */
	SDL_Event ev;       /* structure d'evenement(s) SDL */

#define N_VERTS 4
#define V_SIZE 2

	/* nos donnees */
	float vertices[N_VERTS*V_SIZE] =
	{
		-0.8, -0.8,  /* sommet 0 */
		0.8, -0.8,   /* sommet 1 */
		0.8, 0.8,    /* sommet 2 */
		-0.8, 0.8    /* sommet 3 */
	};


	/* initialisation de la SDL en mode OpenGL */
	SDL_Init(SDL_INIT_VIDEO);
	SDL_SetVideoMode(W, H, 32, SDL_OPENGL);

	/* nom de la fenetre */
	//SDL_WM_SetCaption("Vertex Arrays GL", NULL);

	/* initialisation d'opengl */
	init_gl();

	/* boucle d'affichage principale */
	while(loop)
	{
		/* recuperation d'un evenement */
		SDL_WaitEvent(&ev);

		/* analyse */
		switch(ev.type)
		{
			case SDL_QUIT:
				loop = 0;
				break;

			default:;
		}

		glClear(GL_COLOR_BUFFER_BIT);

		/* activation des tableaux de donnees */
		glEnableClientState(GL_VERTEX_ARRAY);

		/* dessin ... a venir */

		/* on flip les tampons */
		glFlush();
		//SDL_GL_SwapBuffers();
	}

	return 0;
}
