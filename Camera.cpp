//
// Created by george on 24/08/24.
//

#include "Camera.h"

Camera::Camera(const glm::vec3 &pPos, float pitchOffset, float yawOffset) :
    pos{pPos},
    pitch{pitchOffset},
    yaw{-90.0f + yawOffset} {

    update();
}

void Camera::update() {
    facing.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    facing.y = sin(glm::radians(pitch));
    facing.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    facing = glm::normalize(facing);

    view = glm::lookAt(pos, pos + facing, UP);
}

void Camera::setPos(const glm::vec3 &pPos) {
    pos = pPos;
}

void Camera::rotateYaw(float offset) {
    yaw += offset;
}

void Camera::rotatePitch(float offset) {
    pitch += offset;
    if (pitch > 89.0f) pitch = 89.0f;
    else if (pitch < -89.0f) pitch = -89.0f;
}

void Camera::move(const glm::vec3 &dir) {
    glm::vec3 normalDir = glm::normalize(dir);
    pos += speed * normalDir;
}

void Camera::forward(float frameTime) {
    move(facing);
}

void Camera::back(float frameTime) {
    move(-facing);
}