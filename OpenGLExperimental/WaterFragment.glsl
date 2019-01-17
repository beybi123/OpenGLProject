#version 330 core
 out  vec4 FragColor;

flat in vec3 Normal;  
flat in vec3 FragPos;  
in vec3 ViewPos;
uniform vec3 LightPos[4]; 
uniform vec3 viewPos; 
uniform vec3 LightColor[4]; 
uniform vec3 LightIntensity[4]; 
uniform vec3 LightAmbient[4]; 
uniform vec3 LightAmbientIntensity[4]; 
uniform vec3 objectcolor;
 precision highp float;
 in vec2 vCoords;
void main()
{
    // ambient
    vec3 diffuse,specular,ambient;
	vec3 N=normalize(Normal);
	vec3 V,L,H;

	for(int i=0;i<4;i++)
	{

		ambient += LightAmbientIntensity[i] * LightAmbient[i];
		float dist=length(LightPos[i]-FragPos);
		float attenuation=1.0/(.1+.01*dist+.001*dist*dist);

		V=normalize(viewPos-FragPos);
		L=normalize(LightPos[i]-FragPos);
			
		H  = normalize( L + V );  
	
		float Kd = max(dot(L, N), 0.0);
		diffuse += Kd * LightColor[i] *attenuation*LightIntensity[i];
    

		float Ks = pow(max(dot(N, H), 0.0), 32);
		specular += Ks * vec3(1,1,1)*attenuation;  
	}
  
	vec3 result = (diffuse+specular)+ambient;

	 FragColor = vec4(result,.9);
} 

