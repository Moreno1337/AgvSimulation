#include "EBO.h"

void EBO_Load(GLuint* indices, GLsizeiptr size, GLuint* ID)
{
	glGenBuffers(1, ID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, *ID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}

void EBO_Bind(GLuint ID)
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO_Unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO_Delete(GLuint* ID)
{
	glDeleteBuffers(1, ID);
}