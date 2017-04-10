#version 410

flat in vec4 pos;

out vec4 color;

void main () {
	float	grey;

	grey = (0.2125 * pos.x + 0.7154 * pos.y + 0.5721 * pos.z) / 3.0f + 0.4f;
	// grey = 1.0f;
	color = vec4(grey, grey, grey, 45.0f);
}
