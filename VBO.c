#include "VBO.h"

void VBO_Load(GLfloat* vertices, GLsizeiptr size, GLuint* ID)
{
	glGenBuffers(1, ID);
	glBindBuffer(GL_ARRAY_BUFFER, *ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void VBO_Bind(GLuint ID)
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO_Unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VBO_Delete(GLuint* ID)
{
	glDeleteBuffers(1, ID);
}