//
// Created by george on 17/08/24.
//

#ifndef GLBASICS_DISPLAY_H
#define GLBASICS_DISPLAY_H

#include "glinclude.h"

void framebufferSizeCallback(GLFWwindow *window, int width, int height);

class Display {
private:
    int width, height;
    GLFWwindow *window;

    GLfloat background[3] = {0.0f, 0.0f, 0.0f};

    static bool gladInitialised;

public:
    Display(int width, int height, const char *title);
    void close();
    void setBackground(GLfloat r, GLfloat g, GLfloat b);
    void update();
};


#endif //GLBASICS_DISPLAY_H
