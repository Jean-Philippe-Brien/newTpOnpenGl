//
// Created by ssohy on 12/13/2019.
//

#include "Enemy.h"
#include "../Utils/glUtils.h"


Enemy::Enemy(const glm::vec3 &position, std::vector<Node> nMap, int planeSize) : Entity(position) {
    idBaseThank = loadOBJ("assets/thisThank.obj");
    idBaseCanon = loadOBJ("assets/thisThankCanon.obj");
    pathFinding = new aStar(nMap, planeSize);
    alive=true;
}

void Enemy::movement(glm::vec3 playerPos) {
    if(sqrt(pow(position.x - playerPos.x, 2) + pow(position.z - playerPos.z, 2)) <= 14.0) {
        if ((timeLastCheck + timeBetweenCheck) < SDL_GetTicks()) {
            pathFinding->FindPath(position, playerPos);
            timeLastCheck = SDL_GetTicks();
            glm::vec3 destination(pathFinding->getClosedSet()->at(1).getX(),playerPos.y, pathFinding->getClosedSet()->at(1).getY());

        }
    }

}

void Enemy::drawEntity() {
    glPushMatrix();
    
    glTranslatef(position.x, position.y, position.z);
    
    glRotatef(rotation, 0, 1, 0);
    glRotatef(90,0,1,0);
    glScalef(0.2f,0.2f,0.2f);
    glColor3f(0,0,1);
    glCallList(idBaseThank);
    glRotatef( canonRotation,0,1,0);
    glCallList(idBaseCanon);
    glPopMatrix();
}

void Enemy::chase(glm::vec3 pos) {

}




void Enemy::setPos(const glm::vec3 &pos) {
    Entity::setPos(pos);
}
const glm::vec3 &Enemy::getPos() const {
    return Entity::getPos();
}
float Enemy::getRotation() const {
    return Entity::getRotation();
}
void Enemy::setRotation(float rotation) {
    Entity::setRotation(rotation);
}
float Enemy::getCanonRotation() const {
    return Entity::getCanonRotation();
}
void Enemy::setCanonRotation(float canonRotation) {
    Entity::setCanonRotation(canonRotation);
}

aStar *Enemy::getPathFinding() const {
    return pathFinding;
}
