//
// Created by george on 24/08/24.
//

#include "utils.h"

double delta_frame_time() {
    static double lastFrame {0.0f};
    double currentTime = glfwGetTime();
    double delta = currentTime - lastFrame;
    lastFrame = currentTime;

    return delta;
}