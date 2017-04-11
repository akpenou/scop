#version 410

in vec4 vertex_position;

flat out vec4 pos;
out vec4 col;

uniform mat4 center;
uniform mat4 proj;
uniform mat4 view;
uniform mat4 obj_rot;
uniform sampler2D basic_texture;
uniform float fade;

void main () {
	pos = obj_rot * center * vertex_position;
	gl_Position = proj * view * pos;
	pos = vertex_position;
	col = vertex_position;
}
