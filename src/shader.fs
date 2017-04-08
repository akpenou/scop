#version 410

in vec4 pos;

out vec4 color;

void main () {
	color = vec4(pos.xyz, 1.0);
}
