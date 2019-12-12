//
// Created by ssohy on 12/11/2019.
//

#include "Enemy.h"

Enemy::~Enemy() {

}

Enemy::Enemy(const glm::vec3 &position) : Entity(position) {
    idBaseThank = loadOBJ("assets/thisThank.obj");
    idBaseCanon = loadOBJ("assets/thisThankCanon.obj");
}

void Enemy::spawn(glm::vec3 pos) {

}

void Enemy::update(Player *player) {
    movement(player);
}

void Enemy::wander() {

}

void Enemy::chaseTarget() {

}

void Enemy::findPathToTarget() {

}


//Getter & Setter
void Enemy::setPosition(const glm::vec3 &pos) {
    Entity::setPosition(pos);
}


float Enemy::getRotation() const {
    return Entity::getRotation();
}

void Enemy::setRotation(float rotation) {
    Entity::setRotation(rotation);
}

void Enemy::drawEntity() {
    glPushMatrix();
    
    glTranslatef(position.x, position.y, position.z);
    
    glRotatef(rotation, 0, 1, 0);
    glRotatef(90, 0, 1, 0);
    glScalef(0.2f, 0.2f, 0.2f);
    glColor3f(0, 0, 1);
    glCallList(idBaseThank);
    glRotatef(canonRotation, 0, 1, 0);
    glCallList(idBaseCanon);
    glPopMatrix();
}

float Enemy::getCanonRotation() const {
    return Entity::getCanonRotation();
}

void Enemy::setCanonRotation(float canonRotation) {
    Entity::setCanonRotation(canonRotation);
}

float Enemy::getIsAlive() const {
    return Entity::getIsAlive();
}

void Enemy::setIsAlive(float isAlive) {
    Entity::setIsAlive(isAlive);
}

void Enemy::movement(Player *player) {
    
    glm::vec3 direction;
    glm::vec3 diff = (player->getPosition() - this->getPosition());
    float distance = sqrtf(dot(diff, diff));
    
    direction.x = player->getPosition().x - this->getPosition().x;
    direction.z = player->getPosition().z - this->getPosition().z;
    float newX = this->getPosition().x + direction.x * 0.5;
    float newY = this->getPosition().z + direction.z * 0.5;
    direction = {direction.x + newX, direction.y, direction.z + newY};
    
    
}
