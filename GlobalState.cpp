//
// Created by george on 20/08/24.
//

#include "GlobalState.h"

void mouse::callback(GLFWwindow * window, double xpos, double ypos) {
    global().mouseX = xpos;
    global().mouseY = ypos;
}

double mouse::getMouseX() {
    return global().mouseX;
}

double mouse::getMouseY() {
    return global().mouseY;
}