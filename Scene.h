//
// Created by george on 20/08/24.
//

#ifndef GLBASICS_SCENE_H
#define GLBASICS_SCENE_H

#include "Display.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Scene {
private:
    Display &scr;
    const Camera *camera;

public:
    explicit Scene(Display &pScr);
    void bindCamera(const Camera *cam) { camera = cam; }
    ~Scene();
};

#endif //GLBASICS_SCENE_H
