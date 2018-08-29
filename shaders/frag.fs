#version 410

out vec4    frag_colour;
in vec3     u;

void main()
{
  vec3 uv = vec3(cos(u*10.));
  frag_colour = 1.0*vec4( uv.xyz, 1.0);
}

