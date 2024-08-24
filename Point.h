//
// Created by george on 18/08/24.
//

#ifndef GLBASICS_POINT_H
#define GLBASICS_POINT_H
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Point {
private:
    glm::vec3 pos;
public:
    Point(float x, float y, float z);
    [[nodiscard]] float getX() const { return pos.x; }
    [[nodiscard]] float getY() const { return pos.y; }
    [[nodiscard]] float getZ() const { return pos.z; }
};


#endif //GLBASICS_POINT_H
