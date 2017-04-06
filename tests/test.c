#include <OpenGL/glew.h>
#include <OpenGL/gl.h>
#include <stdio.h>
#include <SDL2/SDL.h>

void	sdl_init(void)
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	// SDL_GL_SetAttribute(SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG, GL_TRUE);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

}

int main(int argc, char **argv)
{
	SDL_GLContext	contexteOpenGL;
	SDL_Window*		fenetre;
	SDL_Event		evenements;
	int 			terminer = 0;
	const GLubyte* renderer;
	const GLubyte* version;

	// Vertices
	GLuint	vbo = 0;
	GLuint	vao = 0;
	GLfloat	points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	GLfloat	colours[] = {
		1.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 1.0f,
	};
	
	float matrix[] = { 
		1.0f, 0.0f, 0.0f, 0.0f, // first column 
		0.0f, 1.0f, 0.0f, 0.0f, // second column 
		0.0f, 0.0f, 1.0f, 0.0f, // third column 
		0.5f, 0.0f, 0.0f, 1.0f // fourth column 
	};

	const char* vertex_shader =
		"#version 410\n"
		"layout(location = 0) in vec3 vertex_position;"
		"layout(location = 1) in vec3 vertex_colour;"
		"uniform mat4 matrix;"
		"out vec3 colour;"
		"void main () {"
		"  colour = vertex_colour;"
		"  gl_Position = matrix * vec4 (vertex_position, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 410\n"
		"in vec3 colour;"
		"out vec4 frag_colour;"
		"void main () {"
		"  frag_colour = vec4 (colour, 1.0);"
		"}";


	// Initialisation de la SDL
	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		SDL_Quit();
		return -1;
	}

	sdl_init();

	fenetre = SDL_CreateWindow("Test SDL 2.0", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	// printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	// printf("GL  line %d failed: %d\n", __LINE__, glGetError());

	if (!(contexteOpenGL = SDL_GL_CreateContext(fenetre)))
		printf("SDL_Init failed: %s\n", SDL_GetError());

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
	{
		printf("Glew error\n");
		return (-1);
	}

	renderer = glGetString (GL_RENDERER); /* get renderer string */
	version = glGetString (GL_VERSION); /* version as a string */
	// printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	// printf("GL  line %d failed: %d\n", __LINE__, glGetError());
	printf ("Renderer: %s\n", renderer);
	printf ("OpenGL version supported %s\n", version);

	// Create VBOs
	glEnable (GL_CULL_FACE); // cull face
	glCullFace (GL_BACK); // cull back face
	glFrontFace (GL_CW); // GL_CCW for counter clock-wise”
	
	GLuint points_vbo = 0;
	glGenBuffers(1, &points_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_DYNAMIC_DRAW); //GL_STATIC_DRAW);

	GLuint colours_vbo = 0;
	glGenBuffers(1, &colours_vbo);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(colours), colours, GL_DYNAMIC_DRAW); //GL_STATIC_DRAW);

	// printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	// printf("GL  line %d failed: %d\n", __LINE__, glGetError());

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, points_vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer(GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	printf("GL  line %d failed: %d\n", __LINE__, glGetError());

	GLuint vs = glCreateShader (GL_VERTEX_SHADER);
	glShaderSource (vs, 1, &vertex_shader, NULL);
	glCompileShader (vs);
	GLuint fs = glCreateShader (GL_FRAGMENT_SHADER);
	glShaderSource (fs, 1, &fragment_shader, NULL);
	glCompileShader (fs);
	GLuint shader_programme = glCreateProgram ();
	glAttachShader (shader_programme, fs);
	glAttachShader (shader_programme, vs);
	glLinkProgram (shader_programme);
	printf("SDL line %d failed: %s\n", __LINE__, SDL_GetError());
	printf("GL  line %d failed: %d\n", __LINE__, glGetError());

	if (!fenetre)
	{
		SDL_Quit();
		return (-1);
	}
	// INIT motion
	float speed = 1.0f; // move at 1 unit per second 
	float last_position = 0.0f;

	double previous_time = SDL_GetTicks();
	double current_time = SDL_GetTicks();
	double elapsed_time = current_time - previous_time / 1000;
	int matrix_location = glGetUniformLocation (shader_programme, "matrix");

	while(!terminer)
	{
		current_time = SDL_GetTicks();
		elapsed_time = (current_time - previous_time) / 1000;
		previous_time = current_time;

		if (fabs(last_position) > 1.0f) { 
			speed = -speed; 
		}

		matrix[12] = elapsed_time * speed + last_position;
		last_position = matrix[12];
		glUseProgram (shader_programme);
		glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix);

		// Clear the window
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram (shader_programme);
			glBindVertexArray (vao);
			// draw points 0-3 from the currently bound VAO with current in-use shader
			glDrawArrays (GL_TRIANGLES, 0, 3);
		// Update the window
		SDL_PollEvent(&evenements);
		SDL_GL_SwapWindow(fenetre);
		// SDL_WaitEvent(&evenements);
		if(evenements.window.event == SDL_WINDOWEVENT_CLOSE)
			terminer = 1;
	}
	SDL_GL_DeleteContext(contexteOpenGL);
	SDL_DestroyWindow(fenetre);
	SDL_Quit();
	return 0;
}
