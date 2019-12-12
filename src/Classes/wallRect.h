//
// Created by jean- on 2019-12-10.
//

#ifndef RUSTBUCKETS_WALLRECT_H
#define RUSTBUCKETS_WALLRECT_H

#include "../Utils/Include.h"


class wallRect {
public:
    float halfCubeDimension = 2;
    std::vector<glm::vec3 *> pointWall;
    wallRect(std::vector<char>* map, int planeSize);
    void addCube(glm::vec3 pos);
};


#endif //RUSTBUCKETS_WALLRECT_H
