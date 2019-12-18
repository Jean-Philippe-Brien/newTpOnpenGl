//
// Created by ssohy on 12/9/2019.
//

#include "Entity.h"



Entity::Entity(const glm::vec3 &position) : position(position) {}


void Entity::drawEntity() {

}

void Entity::movement() {



}


//Getter/Setter

float Entity::getSpeed() const {
    return baseSpeed;
}

void Entity::setSpeed(float speed) {
    Entity::baseSpeed = speed;
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
    if(hp <= 0){
        alive = false;
        hp = 0;
    }
}

const glm::vec3 &Entity::getPosition() const {
    return position;
}

void Entity::setPosition(const glm::vec3 &position) {
    Entity::position = position;
}

bool Entity::isAlive() const {
    return alive;
}

void Entity::setIsAlive(bool alive) {
    Entity::alive = alive;
}


