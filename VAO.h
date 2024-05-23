#ifndef __VAO__
#define __VAO__

#include <glad/glad.h>
#include "VBO.h"

void VAO_Load(GLuint* ID);
void VAO_LinkAttrib(GLuint VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset);
void VAO_Bind(GLuint ID);
void VAO_Unbind();
void VAO_Delete(GLuint* ID);

#endif
