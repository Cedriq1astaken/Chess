#include "gui.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "iostream"
#include "Board.h"

/*
 * Setup GUI function from https://github.com/ocornut/imgui/blob/master/imgui_demo.cpp
 */

using namespace std;
Board *board = new Board();
gui myimgui(*board);


void setupGUI() {
    // Setup window
    if (!glfwInit())
        return;

    // GL 3.0 + GLSL 130
    const char *glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);


    // Create window with graphics context
    GLFWwindow *window = glfwCreateWindow(1280, 1280, "Chess Board", NULL, NULL);
    if (window == NULL)
        return;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
        throw("Unable to context to OpenGL");

    int screen_width, screen_height;
    glfwGetFramebufferSize(window, &screen_width, &screen_height);
    glViewport(0, 0, screen_width, screen_height);
    myimgui.Init(window, glsl_version);
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        myimgui.NewFrame();
        myimgui.Update();
        myimgui.Render();
        glfwSwapBuffers(window);
    }
    myimgui.Shutdown();
}


int main(){


    setupGUI();
    return 0;
}