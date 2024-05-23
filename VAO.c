#include "VAO.h"

void VAO_Load(GLuint* ID)
{
	glGenVertexArrays(1, ID);
}

void VAO_LinkAttrib(GLuint VBO, GLuint layout, GLuint numComponents, GLenum type, GLsizeiptr stride, void* offset)
{
	VBO_Bind(VBO);
	glVertexAttribPointer(layout, numComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO_Unbind();
}

void VAO_Bind(GLuint ID)
{
	glBindVertexArray(ID);
}

void VAO_Unbind()
{
	glBindVertexArray(0);
}

void VAO_Delete(GLuint* ID)
{
	glDeleteVertexArrays(1, &ID);
}