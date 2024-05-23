#include "main.h"

int main(void)
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLfloat vertices[] =
    {
        // | ---------------- COORDINATES --------------- | ----- COLORS ----- |
            -0.5f, -0.5f * (float)sqrt(3) / 3,      0.0f,   0.8f, 0.3f, 0.02f,
             0.5f, -0.5f * (float)sqrt(3) / 3,      0.0f,   0.8f, 0.3f, 0.02f,
             0.0f,  0.5f * (float)sqrt(3) * 2 / 3,  0.0f,   1.0f, 0.6f, 0.32f,
            -0.25f, 0.5f * (float)sqrt(3) / 6,      0.0f,   0.9f, 0.45f, 0.17f,
             0.25f, 0.5f * (float)sqrt(3) / 6,      0.0f,   0.9f, 0.45f, 0.17f,
             0.0f, -0.5f * (float)sqrt(3) / 3,      0.0f,   0.8f, 0.3f, 0.02f
    };

    GLuint indices[] =
    {
        0, 3, 5,
        3, 2, 4,
        5, 4, 1
    };

    GLFWwindow* window = glfwCreateWindow(800, 800, "AGV SIMULATION", NULL, NULL);

    if (!window)
    {
        printf("ERROR: FAILED TO GENERATE WINDOW");
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    gladLoadGL();
    glViewport(0, 0, 800, 800);

    Shader ShaderProgram;
    Shader_Load("./default.vert", "./default.frag", &ShaderProgram);

    GLuint VAO1, VBO1, EBO1;

    VAO_Load(&VAO1);
    VBO_Load(&vertices, sizeof(vertices), &VBO1);
    VAO_Bind(VAO1);
    EBO_Load(&indices, sizeof(indices), &EBO1);

    VAO_LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO_LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    VBO_Unbind();
    VAO_Unbind();
    EBO_Unbind();

    GLuint uniID = glGetUniformLocation(ShaderProgram.ID, "scale");

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        Shader_Activate(ShaderProgram.ID);
        glUniform1f(uniID, 0.5f);

        glBindVertexArray(VAO1);
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    VAO_Delete(&VAO1);
    VBO_Delete(&VBO1);
    EBO_Delete(&EBO1);
    Shader_Delete(ShaderProgram.ID);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}