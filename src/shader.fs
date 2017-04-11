#version 410

flat in vec4 pos;
in vec4 col;
out vec4 color;

uniform sampler2D basic_texture;
uniform float fade;

void main () {
	float	grey;
	vec4	texcolor;
	vec4	solidcolor;

	grey = (abs(pos.x) * 0.1f + abs(pos.y) * 0.4f + abs(pos.z) * 0.2f) / 3.0f + 0.2f;
	solidcolor = vec4(grey, grey, grey, 1.0f);
	texcolor = texture(basic_texture, col.xy);
	color = mix(solidcolor, texcolor, fade);
}
