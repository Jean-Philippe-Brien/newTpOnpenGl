//
// Created by ssohy on 12/9/2019.
//

#include "Entity.h"




void Entity::drawEntity() {

}

void Entity::movement() {



}


//Getter/Setter
float Entity::getIsAlive() const {
    return isAlive;
}

void Entity::setIsAlive(float isAlive) {
    Entity::isAlive = isAlive;
}

float Entity::getSpeed() const {
    return speed;
}

void Entity::setSpeed(float speed) {
    Entity::speed = speed;
}

const glm::vec3 &Entity::getPos() const {
    return position;
}

void Entity::setPos(const glm::vec3 &pos) {
    Entity::position = pos;
}

float Entity::getCanonSpeed() const {
    return canonSpeed;
}

void Entity::setCanonSpeed(float canonSpeed) {
    Entity::canonSpeed = canonSpeed;
}

float Entity::getRotation() const {
    return rotation;
}

void Entity::setRotation(float rotation) {
    Entity::rotation = rotation;
}

float Entity::getCanonRotation() const {
    return canonRotation;
}

void Entity::setCanonRotation(float canonRotation) {
    Entity::canonRotation = canonRotation;
}



double Entity::getHp() const {
    return hp;
}

void Entity::setHp(double hp) {
    Entity::hp = hp;
}

Entity::Entity(const glm::vec3 &position) : position(position) {}

const glm::vec3 &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const glm::vec3 &position) {
    Entity::position = position;
}

const glm::vec3 &Entity::getDirection() const {
    return direction;
}

void Entity::setDirection(const glm::vec3 &direction) {
    Entity::direction = direction;
}
