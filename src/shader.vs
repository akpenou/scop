#version 410

in vec4 vertex_position;

uniform mat4 proj;
uniform mat4 view;

void main () {
	gl_Position = proj * view * vertex_position;
}
