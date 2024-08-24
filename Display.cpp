//
// Created by george on 17/08/24.
//

#include "Display.h"
#include "glinclude.h"
#include "keys.h"
#include "GlobalState.h"
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

    if (!gladInitialised) {
        gladInitialised = gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
        if (!gladInitialised) {
            std::cerr << "Failed to initialise GLAD" << std::endl;
            glfwTerminate();
            exit(EXIT_FAILURE);
        }
    }
    glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
    glfwSetCursorPosCallback(window, mouse::callback);
}

void Display::close() {
    glfwSetWindowShouldClose(window, true);
}

bool Display::isOpen() const {
    return !glfwWindowShouldClose(window);
}

void Display::update() {
    glfwSwapBuffers(window);
    glfwPollEvents();
}

bool Display::keyPressed(Key target) const {
    return glfwGetKey(window, static_cast<int>(target));
}

void Display::disableCursor() {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void Display::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

void Display::fill(const std::array<GLfloat, 3> &colour) {
    glClearColor(colour[0], colour[1], colour[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void Display::enableCursor() {
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
}
