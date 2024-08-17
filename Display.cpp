//
// Created by george on 17/08/24.
//

#include "Display.h"
#include "glinclude.h"
#include <iostream>

void framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Display::Display(int pWidth, int pHeight, const char *title) : width{pWidth}, height{pHeight} {
    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (window == nullptr) {
        std::cerr << "Failed to create GLFW window." << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
}

void Display::close() {
    glfwWindowShouldClose(window);
}

void Display::setBackground(GLfloat r, GLfloat g, GLfloat b) {
    background[0] = r;
    background[1] = g;
    background[2] = b;
}

void Display::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();

    glClearColor(background[0], background[1], background[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}
