//
// Created by jean- on 2019-12-10.
//

#include "CollisionManager.h"

void CollisionManager::init(std::vector<char>* map, int planeSize) {
    wall = new wallRect(map, planeSize);
}

void CollisionManager::Update() {

}
bool CollisionManager::detectColosion(glm::vec3 posToVerify, float halfWhidth) {
    for(glm::vec3* p : wall->pointWall) {
        float distance = sqrt(pow(p->x - posToVerify.x, 2) + 0 +
                              pow(p->z - posToVerify.z, 2));
        float sumHalf = 0.5f + halfWhidth;
        if (distance < sumHalf)
            return true;
    }
    return false;
}
