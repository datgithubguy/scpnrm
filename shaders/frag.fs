#version 410

out vec4    	frag_colour;
in float		vid;
uniform float   time;
uniform float	idmax;

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
  frag_colour = vec4( get_col(vid), 1.0);
}

