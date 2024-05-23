#ifndef __SHADER__
#define __SHADER__

#include <stdio.h>
#include <math.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "fileUtils.h"

typedef struct {
	GLuint ID;
	const char* vertexSource;
	const char* fragmentSource;
} Shader;

void Shader_Load(const char* vertexFile, const char* fragmentFile, Shader* ShaderParams);
void Shader_Activate(GLuint ShaderID);
void Shader_Delete(GLuint ShaderID);

void CompileErrors(unsigned int shader, const char* type);

#endif