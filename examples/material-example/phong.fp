#version 140

in mediump vec2 var_texcoord0;
in mediump vec3 var_position;
in mediump vec3 var_normal;

out vec4 out_fragColor;

const vec3 lightPos = vec3(1.0,1.0,1.0);
const vec3 diffuseColor = vec3(0.5, 0.5, 0.5);
const vec3 specColor = vec3(0.7, 0.7, 0.7);

void main()
{
	vec3 lightDir = normalize(lightPos - var_position);
	vec3 normal = normalize(var_normal);
	
	float lambertian = max(dot(lightDir, normal), 0.0);
	float specular = 0.0;
	
	if (lambertian > 0.0)
	{
		vec3 viewDir = normalize(-var_position);
		vec3 halfDir = normalize(lightDir + viewDir);
		float specAngle = max(dot(halfDir, normal), 0.0);
		specular = pow(specAngle, 32.0);
	}

	out_fragColor = vec4(lambertian * diffuseColor + specular * specColor, 1.0);
}