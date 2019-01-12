#pragma once
#include "Object.h"
#include "Shader.h"

using namespace std;
class GameObject :public Object {

public:
	void load_obj(string path, bool includetexandnormals);
	void load_obj(string path, bool includetexandnormals,GLfloat scale);
	void Draw(mat4 view, mat4 pro);
	void Draw(mat4 view, mat4 pro,GLboolean asArray, GLuint cubemapTexture);
	void SetupMesh();
	void Deform(vec3 ScaleModifier, GLfloat deformModifier);
	void Bind(GLuint program);
	void PrintRandomVertex();
	void ResetVertices();
	//remove useshader func and add a shader class
	GLuint VAO, VBO, EBO,Texture,VBOtexture, VBOnormal;

	Shader shader;
	string  texturePath;


	vector<vec4> BaseVertices;
	vector<vec4> DeformedVertices;
	vector<vec3> Normals;
	vector<vec2> textureCoordinate;

	vector<GLuint> VertexIndices;
	vector<GLuint> NormalIndices;
	vector<GLuint> TextureIndices;

	vec3 pivot = vec3(0,0,0);


	//constructors
	GameObject(string name,string modelPath, bool hastextureandnormals,string vShader,string fShader): Object(name)
	{
		load_obj(modelPath, hastextureandnormals);
		shader =  Shader(vShader, fShader);
	}GameObject(string name, string modelPath, bool hastextureandnormals, Shader shader) : Object(name)
	{
		load_obj(modelPath, hastextureandnormals);
		this->shader = shader;
	}GameObject(string name, string modelPath, bool hastextureandnormals, Shader shader,GLfloat scale) : Object(name)
	{
		load_obj(modelPath, hastextureandnormals, scale);
		this->shader = shader;
	}GameObject() : Object()
	{
	}
};