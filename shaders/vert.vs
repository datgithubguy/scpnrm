#version 410

in vec3         uv;
out vec3        u;
uniform float   time;
uniform mat4	matrix;
uniform vec3	displ;
out float       t;
uniform vec3	median;
uniform float	idmax;
out float vid;

void main()
{
	float scale = 4.;
	vid = float(gl_VertexID);
    t = time;
	u = uv;
    float aspect = 1920./1440.;
	float aa = 1./(tan(1.58/2.));
	float near = .050;
	float far  = 10.01;
	float W = aspect*atan(1.58/2.);
	float H = W;
	float Q = far/(far-near);
	mat4 perspective = mat4(
				W, .0, .0, .0, 
				.0, H, .0, .0,
				.0, .0, -(far+near)/(far-near), -2.*(near*far)/(far-near),
				.0, .0, -1., 1.0
	);

	mat4 world_proj = mat4(
				1./1., .0, .0, .0, 
				.0, 1./1., .0, .0,
				.0, .0, -2./(far-near), -(far+near)/(far-near),
				.0, .0, .0, 1.0
	);
	u -= median/idmax;
	gl_Position =  ((matrix * vec4(u, scale)
	));
	gl_Position *= world_proj;
	gl_Position.xyz += -displ;
	gl_Position *= perspective;
}
