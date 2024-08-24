//
// Created by george on 20/08/24.
//

#include "Scene.h"

//
// Created by george on 18/08/24.
//
#include "keys.h"

Camera::Camera(const glm::vec3 &pPos, float pitchOffset, float yawOffset) :
        pos{pPos},
        pitch{pitchOffset},
        yaw{-90.0f + yawOffset} {

    // Set up view
    updateYaw();
    updatePitch();
    updateView();
}

void Camera::updateYaw() {
    facing.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    facing.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));

    facing = glm::normalize(facing);
}

void Camera::updatePitch() {
    facing.y = sin(glm::radians(pitch));

    facing = glm::normalize(facing);
}

void Camera::setPos(const glm::vec3 &pPos) {
    pos = pPos;
    updateView();
}

void Camera::rotateYaw(float offset) {
    yaw += offset;
    updateYaw();
    updateView();
}

void Camera::rotatePitch(float offset) {
    pitch += offset;
    if (pitch > 89.0f) pitch = 89.0f;
    else if (pitch < -89.0f) pitch = -89.0f;

    updatePitch();
    updateView();
}

void Camera::move(const glm::vec3 &dir, float frameTime) {
    glm::vec3 normalDir = glm::normalize(dir);
    pos += speed * frameTime * normalDir;
    updateView();
}

void Camera::forward(float frameTime) {
    move(facing, frameTime);
}

void Camera::back(float frameTime) {
    move(-facing, frameTime);
}

Scene::~Scene() {
    scr.enableCursor();
}

void Scene::timeFrame() {
    auto currentFrame = static_cast<float>(glfwGetTime());
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
}

Scene::Scene(Display &pScr) : scr{pScr} {
    scr.disableCursor();
}

void Scene::setCamera(const glm::vec3 &pPos, float pitchOffset, float yawOffset) {
    camera = {pPos, pitchOffset, yawOffset};
}

void Scene::moveCamera(glm::vec3 dir) {
    camera.move(dir, deltaTime);
}

void Scene::cameraForward() {
    camera.forward(deltaTime);
}

void Scene::cameraBack() {
    camera.back(deltaTime);
}
