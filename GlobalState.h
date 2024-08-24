//
// Created by george on 20/08/24.
//

#ifndef GLBASICS_GLOBALSTATE_H
#define GLBASICS_GLOBALSTATE_H
#include "glinclude.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace {
    class GlobalState {
    private:

        GlobalState() = default;

    public:
        double mouseX, mouseY;

        GlobalState(const GlobalState &) = delete;

        GlobalState &operator=(const GlobalState &) = delete;

        static GlobalState &get() {
            static GlobalState instance;
            return instance;
        }
    };

    GlobalState &global() { return GlobalState::get(); }
}

namespace mouse {
    void callback(GLFWwindow *window, double xpos, double ypos);

    double getMouseX();

    double getMouseY();
}
#endif //GLBASICS_GLOBALSTATE_H
