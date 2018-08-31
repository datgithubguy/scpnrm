#version 410

out vec4    		frag_colour;
in float			vid;
uniform float   	time;
uniform float		idmax;
uniform float		toogle;
uniform sampler2D	myTextureSampler;
in vec3 u;

vec3	get_col(float rid)
{
return	(vec3
        (
    		(sin(rid+time+0.00) )
            ,
            (sin(rid+time+1.04) )
            ,
            (sin(rid+time+2.08) )
        ));
}

void main()
{
	vec3	col = mix(texture(myTextureSampler, u.zy*2.).xyz, get_col(vid), toogle);
	frag_colour = vec4( col, 1.0);
}

