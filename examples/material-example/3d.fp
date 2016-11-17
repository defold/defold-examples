varying mediump vec2 var_texcoord0;
varying mediump vec3 var_position;

uniform lowp sampler2D LEFT;
uniform lowp sampler2D RIGHT;

void main() {	
	vec4 rc = texture2D(RIGHT, var_texcoord0.xy);
	rc.x = 0.0;
	vec4 lc = texture2D(LEFT, var_texcoord0.xy);
	lc.y = 0.0;
	lc.z = 0.0;
    gl_FragColor = lc + rc;
}