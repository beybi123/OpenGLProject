#pragma once
#include <Angel_commons/Angel.h>

using namespace std;
class Transform
{
public:

	Transform(string Nname)
	{
		name = Nname;
	};
	Transform()
	{
		
	};
	void Translate(vec3 translationvector, float deltaTime);
	void Translate(vec3 vec);
	void Moveto(vec3 vec);
	void Scale();
	void Rotate(GLfloat x, GLfloat y, GLfloat z);
		void Rotate(vec3 rot);
	void ResetRotation();
	void Debug();
	vec3 position = vec3(0, 0, 0);
	vec3 scale;
	string name;
	vec4 forward = position+vec3(0,0,1);

	GLfloat rotX=0.0f, rotY = 0.0f, rotZ = 0.0f;



private:
	
	
};