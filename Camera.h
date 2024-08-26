//
// Created by george on 24/08/24.
//

#ifndef GLBASICS_CAMERA_H
#define GLBASICS_CAMERA_H

#include "Scene.h"
#include "GlobalState.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Camera {
private:
    glm::mat4 view;
    glm::vec3 pos;
    glm::vec3 facing;
    static inline const glm::vec3 UP {0.0f, 1.0f, 0.0f};
    float speed {0.0f};

    float yaw;
    float pitch;

    void update();

public:
    Camera(const glm::vec3 &pPos, float pitchOffset, float yawOffset);
    Camera() : Camera({0.0f, 0.0f, 0.0f}, 0.0f, 0.0f) {};

    [[nodiscard]] const glm::mat4& getView() const { return view; }

    // This should not be used to repeatedly move the camera in the same way as move()
    // because frame time is not taken into account
    void setPos(const glm::vec3 &pPos);
    void setYaw(float pYaw) { yaw = -90.0f + pYaw; }
    void setPitch(float pPitch) { pitch = pPitch; }

    // The way the camera moves depends on what kind of camera it is.
    // void translatePos(const glm::vec3 &dir);
    void rotateYaw(float offset);
    void rotatePitch(float offset);
    void setSpeed(float pSpeed) { speed = pSpeed; }

    void move(const glm::vec3 &dir);
    void forward(float frameTime);
    void back(float frameTime);
};

#endif //GLBASICS_CAMERA_H
