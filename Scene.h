//
// Created by george on 20/08/24.
//

#ifndef GLBASICS_SCENE_H
#define GLBASICS_SCENE_H

#include "Display.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Scene {
private:
    Display &scr;
    Camera camera;

    float lastFrame {0.0f};
    float deltaTime;

    void timeFrame();

public:
    explicit Scene(Display &pScr);
    void setCamera(const glm::vec3 &pPos, float pitchOffset, float yawOffset);
    void moveCamera(glm::vec3 dir);
    void cameraForward();
    void cameraBack();
    ~Scene();
};


class Camera {
private:
    glm::mat4 view;
    glm::vec3 pos;
    glm::vec3 facing;
    static inline const glm::vec3 UP {0.0f, 1.0f, 0.0f};
    float speed {0.0f};

    float yaw;
    float pitch;

    void updateView() { view = glm::lookAt(pos, pos + facing, UP); }
    void updateYaw();
    void updatePitch();

public:
    Camera(const glm::vec3 &pPos, float pitchOffset, float yawOffset, const Scene& scene);
    explicit Camera(const Scene& pScene) : Camera({0.0f, 0.0f, 0.0f}, 0.0f, 0.0f, pScene) {};
    void setPos(const glm::vec3 &pPos);

    // The way the camera moves depends on what kind of camera it is.
//    void translatePos(const glm::vec3 &dir);
    void rotateYaw(float offset);
    void rotatePitch(float offset);
    void setSpeed(float pSpeed) { speed = pSpeed; }

    void move(const glm::vec3 &dir, float frameTime);
    void forward(float frameTime);
    void back(float frameTime);
};


#endif //GLBASICS_SCENE_H
