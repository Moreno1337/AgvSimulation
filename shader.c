#include "shader.h"

void Shader_Load(const char* vertexFile, const char* fragmentFile, Shader* ShaderParams)
{
	ShaderParams->vertexSource = FL_ReadFile(vertexFile);
    ShaderParams->fragmentSource = FL_ReadFile(fragmentFile);

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &ShaderParams->vertexSource, NULL);
    glCompileShader(vertexShader);
    CompileErrors(vertexShader, "VERTEX");

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &ShaderParams->fragmentSource, NULL);
    glCompileShader(fragmentShader);
    CompileErrors(fragmentShader, "FRAGMENT");

    ShaderParams->ID = glCreateProgram();

    glAttachShader(ShaderParams->ID, vertexShader);
    glAttachShader(ShaderParams->ID, fragmentShader);

    glLinkProgram(ShaderParams->ID);
    CompileErrors(ShaderParams->ID, "PROGRAM");

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}

void Shader_Activate(GLuint ShaderID)
{
    glUseProgram(ShaderID);
}

void Shader_Delete(GLuint ShaderID)
{
    glDeleteProgram(ShaderID);
}

void CompileErrors(unsigned int shader, const char* type)
{
    GLint hasCompiled;
    char infolog[1024];

    if (type != "PROGRAM")
    {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &hasCompiled);

        if (hasCompiled == GL_FALSE)
        {
            glGetShaderInfoLog(shader, 1024, NULL, infolog);
            printf("SHADER COMPILATION ERROR for: %s", type);
        }
    }
    else
    {
        glGetProgramiv(shader, GL_COMPILE_STATUS, &hasCompiled);

        if (hasCompiled == GL_FALSE)
        {
            glGetProgramInfoLog(shader, 1024, NULL, infolog);
            printf("SHADER LINKING ERROR for: %s", type);
        }
    }
}