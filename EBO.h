#ifndef __EBO__
#define __EBO__

#include <glad/glad.h>

void EBO_Load(GLuint* indices, GLsizeiptr size, GLuint* ID);
void EBO_Bind(GLuint ID);
void EBO_Unbind();
void EBO_Delete(GLuint* ID);

#endif