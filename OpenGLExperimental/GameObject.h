#pragma once
#include "Object.h"
#include "Shader.h"
#include "Light.h"
#include "Vertex.h"

using namespace std;
class GameObject :public Object {


public:
	

	
	void load_obj(string path, bool includetexandnormals);
	void Draw(mat4 view, mat4 pro, GLfloat time, Light Light[4], vec3 Camerapos, GLuint &usebump);
	void SetupMesh(GLboolean cubemap);
	void SetupMesh();
	void Deform(vec3 ScaleModifier, GLfloat deformModifier);
	void Bind(GLuint program);
	void BindScaledVertexList();
	void PrintRandomVertex();
	void ResetVertices();
	void SwitchShader(Shader &shader);
	GLuint loadCubemap(vector<string> faces);
	//remove useshader func and add a shader class
	GLuint VAO, VBO, EBO,Texture,VBOtexture, VBOnormal,VBOTangent,VBOBitangent;

	Shader shader;
	string  texturePath;

	//base values
	vector<vec4> VertexPositions;
	vector<vec3> Normals;
	vector<vec2> TextureCoordinates;

	vector<vec4> EndVertexPositions;
	vector<vec3> EndNormals;
	vector<vec2> EndTextureCoordinates;

	vector<vec3> Tangents,Bitangents;

	//endlist
	vector<Vertex> vertexList;
	vector<Vertex> AllVertexList;
	//other vertex formations
	vector<vec4> DeformedVertices;
	vector<vec4> ScaledVertices;

	vector<GLuint> VertexIndices;

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
	}GameObject() : Object()
	{
	}

	
};