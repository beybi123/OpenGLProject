#pragma once
#include <string>
#include <Angel_commons/Angel.h>
using namespace std;
class Shader {

public:
	string name;

	
	GLuint getAttr(const char * name);
	GLuint getShaderID();
	GLuint getModelID();
	GLuint getProjectionID();
	GLuint getViewID();


	string v_path, f_path;

	void Load(string vertexPath, string fragmentPath);
	void Use();

	Shader(string vertexPath, string fragmentPath) {
		Load(vertexPath, fragmentPath);
		LocationTime = glGetUniformLocation(sID, "time");
		LightPosLocation= glGetUniformLocation(sID, "LightPos");
		CameraPosLocation = glGetUniformLocation(sID, "ViewPos");
		LightColorLocation = glGetUniformLocation(sID, "LightColor");
		LightDirLocation = glGetUniformLocation(sID, "LightDir");
		
		v_path = vertexPath;
		f_path = fragmentPath;
		
	}Shader() {
	}

	GLuint LocationTime, LightPosLocation, LightDirLocation, CameraPosLocation, LightColorLocation, LightIntensityLocation,LightAmbientLocation
		,LightAmbientIntensityLocation,RotationLocation,
		textureLocation,normalMapLocation,skyboxLocation,UseBumpMapLocation, UseTextureLocation;
	GLuint material_color, material_smoothness, material_specular;
	GLuint sID,ProjectionID,ModelID,ViewID;
};