#version 410

flat in vec4 pos;
out vec4 color;

uniform sampler2D basic_texture;

void main () {
	float	grey;

	grey = (0.2125 * abs(pos.x) + 0.3154 * abs(pos.y) + 0.3721 * abs(pos.z)) / 3.0f + 0.2f;
	// grey = 1.0f;
	color = vec4(grey, grey, grey, 1.0f);
	// color = texture(basic_texture, gl_FragCoord.xy);
	// color = vec4(gl_FragCoord.wyz, 1.0f);
	// vec2 texcoord = ((gl_FragCoord.xy - adjust.xy) / scale.xy) / textureSize(sampler0);
	// color = vec4(uv, 1.0f, 1.0f);
	// color = vec4(gl_PointCoord, 1.0f, 1.0f);
}
