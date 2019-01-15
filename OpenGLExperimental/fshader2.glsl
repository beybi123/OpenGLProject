#version 330 core
out vec4 FragColor;

in vec3 Normal;  
in vec3 FragPos;  
in vec3 ViewPos;

uniform vec3 LightPos; 
uniform vec3 LightColor; 
void main()
{
    // ambient
  // ambient
    float ambientStrength = 0.25;
    vec3 ambient = ambientStrength * vec3(1,1,1);
  	
	vec3 N=normalize(Normal);
	vec3 V=normalize(ViewPos-FragPos);
	vec3 L=normalize(LightPos-FragPos);
    // diffuse 
	vec3 H = normalize( L + V );  
	
    float Kd = max(dot(L, N), 0.0);
    vec3 diffuse = Kd * vec3(1,1,1);
    

    float Ks = pow(max(dot(N, H), 0.0), 128);
    vec3 specular = Ks * vec3(1,1,1);  

	float dist=length(LightPos-FragPos);
	float attenuation=1.0/(.01+.001*dist+.0001*dist*dist);

	//*LightColor
	vec3 result = (diffuse+ambient+specular);
    FragColor = vec4(result, 1.0);


} 