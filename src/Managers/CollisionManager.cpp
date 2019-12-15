//
// Created by jean- on 2019-12-10.
//

#include "CollisionManager.h"

void CollisionManager::init(std::vector<char>* map, int planeSize) {
    wall = new wallRect(map, planeSize);
}

void CollisionManager::Update() {

}
bool CollisionManager::detectWallCollision(glm::vec3 posToVerify, float halfWhidth) {
    for(glm::vec3* p : wall->pointWall) {
        float distance = sqrt(pow(p->x - posToVerify.x, 2) + pow(p->z - posToVerify.z, 2));
        float sumHalf = 0.5+halfWhidth;
        if (distance < sumHalf)
            return true;
    }
    return false;
}

bool CollisionManager::detectBulletCollision(glm::vec3 bulletPos, glm::vec3 entityPos) {
    if(bulletPos.x<=entityPos.x+0.5f && bulletPos.x >=entityPos.x-0.5f){
        if(bulletPos.z<=entityPos.z+0.2f && bulletPos.z >= entityPos.z -0.2f){
            return true;
        }
    }
    return false;
}
