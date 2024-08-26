//
// Created by george on 20/08/24.
//

#include "Scene.h"

//
// Created by george on 18/08/24.
//
#include "keys.h"

Scene::Scene(Display &pScr) : scr{pScr} {
    scr.disableCursor();
}

Scene::~Scene() {
    scr.enableCursor();
}