//
// Created by jean- on 2019-12-07.
//

#include "Player.h"

Player::Player(const glm::vec3 pos) : Entity(pos) {
    idBaseThank = loadOBJ("assets/thisThank.obj");
    idBaseCanon = loadOBJ("assets/thisThankCanon.obj");
    

}

Player::~Player() {
    glDeleteLists(idBaseThank, 1);
}

void Player::movement(bool forward, CollisionManager *cm) {
    speed = 0.05;
    float tempX = 0;
    float tempY = 0;
    if(forward) {
        tempX = position.x + speed * cos(rotation * (M_PI / 180));
        tempY = position.z - speed * sin(rotation * (M_PI / 180));
    } else {

        tempX = position.x - speed * cos(rotation * (M_PI / 180));
        tempY = position.z + speed * sin(rotation * (M_PI / 180));
    }
    if(!cm->detectColosion(glm::vec3(tempX, 0, tempY),0.5)){
        position.x = tempX;
        position.z = tempY;
    }
}

void Player::drawEntity() {

    glPushMatrix();

        glTranslatef(position.x, position.y, position.z);
        
        glRotatef(rotation, 0, 1, 0);
        drawAxe();
        glRotatef(90,0,1,0);
        glScalef(0.2f,0.2f,0.2f);
        glColor3f(0,0,1);
        glCallList(idBaseThank);
        glRotatef( canonRotation,0,1,0);
        glCallList(idBaseCanon);
    glPopMatrix();

}

//Getter // Setter
const glm::vec3 &Player::getPos() const {
    return Entity::getPos();
}

void Player::setPos(const glm::vec3 &pos) {
    Entity::setPos(pos);
}

float Player::getRotation() const {
    return Entity::getRotation();
}

void Player::setRotation(float rotation) {
    Entity::setRotation(rotation);
}

float Player::getCanonRotation() const {
    return Entity::getCanonRotation();
}

void Player::setCanonRotation(float canonRotation) {
    Entity::setCanonRotation(canonRotation);
}


float Player::getFireRate1() const {
    return fireRate;
}

float Player::getLastFire() const {
    return lastFire;
}

void Player::setLastFire(float lastFire) {
    Player::lastFire = lastFire;
}