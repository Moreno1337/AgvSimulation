#ifndef __VBO__
#define __VBO__

#include <glad/glad.h>

void VBO_Load(GLfloat* vertices, GLsizeiptr size, GLuint* ID);
void VBO_Bind(GLuint ID);
void VBO_Unbind();
void VBO_Delete(GLuint* ID);

#endif
