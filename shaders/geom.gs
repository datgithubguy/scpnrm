#version 410

layout(triangles) in;
layout(triangle_strip, max_vertices = 3) out;
uniform float time;

in gl_PerVertex
{
  vec4 gl_Position;
} gl_in[];

out gl_PerVertex
{
  vec4 gl_Position;
} gl_out;

out vec3 normal;
out vec3 u;

void	main()
{
float id = float(gl_PrimitiveIDIn);
mat2 m = mat2(cos(time*1.), sin(time*1.), -sin(time*1.), cos(time*1.) );
//	if (mod(id+floor(time*8.), 5.) >= +floor(time*1.) )
	if (id < floor(time*1000.))
	for (int i = 0; i < 3; i++)
	{
		gl_out.gl_Position = 
		gl_in[i].gl_Position-vec4(-.0,.0,.0, .0);
		gl_out.gl_Position.xz *= m;
		u = gl_out.gl_Position.xyz;
		vec3 tmp_0, tmp_1, tmp_2;
		tmp_0 = gl_in[2].gl_Position.xyz;
		tmp_1 = gl_in[1].gl_Position.xyz;
		tmp_2 = gl_in[0].gl_Position.xyz;
//		tmp_0.xz *= m;
//		tmp_1.xz *= m;
//		tmp_2.xz *= m;
//		vec3 A = tmp_0 - tmp_2;
//	    vec3 B = tmp_1 - tmp_2;
//	    normal = normalize(cross(A,B));
	    //gl_out.gl_Position.xyz += normal*-.01f*abs(sin(time*8.));
		EmitVertex();
	}
	EndPrimitive();
}
