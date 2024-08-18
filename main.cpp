//
// Created by george on 17/08/24.
//

#include "glbasics.h"
#include <iostream>

int main() {
    init();
    Display screen {300, 400, "Test"};
    screen.setBackground(1.0f, 0.0f, 0.3f);

    while (screen.isOpen()) {
        if (screen.keyPressed(Key::escape)) {
            std::cout << "Screen closed." << std::endl;
            screen.close();
        }
        screen.update();
    }
    screen.close();
    return 0;
}