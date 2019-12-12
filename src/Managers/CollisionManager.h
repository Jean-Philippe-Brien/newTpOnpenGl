//
// Created by jean- on 2019-12-10.
//

#ifndef RUSTBUCKETS_COLLISIONMANAGER_H
#define RUSTBUCKETS_COLLISIONMANAGER_H


#include "../Utils/Include.h"
#include "../Classes/wallRect.h"

class CollisionManager {
private:
    wallRect *wall;
public:
    void init(std::vector<char>* map, int planeSize);
    void Update();
    bool detectColosion(glm::vec3 player, float halfWhidth);
};


#endif //RUSTBUCKETS_COLLISIONMANAGER_H
