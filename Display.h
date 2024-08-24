//
// Created by george on 17/08/24.
//

#ifndef GLBASICS_DISPLAY_H
#define GLBASICS_DISPLAY_H

#include "glinclude.h"
#include "keys.h"
#include <array>

void framebufferSizeCallback(GLFWwindow *window, int width, int height);

class Display {
private:
    int width, height;
    GLFWwindow *window;

    static inline bool gladInitialised {false};

public:
    Display(int width, int height, const char *title);
    void close();
    [[nodiscard]] bool isOpen() const;
    static void fill(const std::array<GLfloat, 3> &colour);
    void update();
    [[nodiscard]] bool keyPressed(Key target) const;
    void disableCursor();
    void enableCursor();

    static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
};


#endif //GLBASICS_DISPLAY_H
