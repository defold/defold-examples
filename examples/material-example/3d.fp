#version 140

in mediump vec2 var_texcoord0;
in mediump vec3 var_position;

out vec4 out_fragColor;

uniform lowp sampler2D LEFT;
uniform lowp sampler2D RIGHT;

void main()
{
	vec4 rc = texture(RIGHT, var_texcoord0.xy);
	rc.x = 0.0;
	vec4 lc = texture(LEFT, var_texcoord0.xy);
	lc.y = 0.0;
	lc.z = 0.0;
	out_fragColor = lc + rc;
}