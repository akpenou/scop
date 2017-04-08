#version 410

in vec4 vertex_position;

out vec4 pos;

uniform mat4 center;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 rot;

void main () {
	pos = rot * center * vertex_position;
	gl_Position = proj * view * pos;
}
