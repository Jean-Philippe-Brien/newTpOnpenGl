//
// Created by ssohy on 12/13/2019.
//

#include "Enemy.h"

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

void Enemy::movement() {
    Entity::movement();
}

void Enemy::drawEntity() {
    Entity::drawEntity();
}

void Enemy::setPos(const glm::vec3 &pos) {
    Entity::setPos(pos);
}

Enemy::Enemy(const glm::vec3 &position) : Entity(position) {}

void Enemy::chase(glm::vec3 pos) {

}


