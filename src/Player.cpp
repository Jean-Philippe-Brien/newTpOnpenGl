//
// Created by jean- on 2019-12-07.
//

#include "Player.h"
#include "Classes/Entity.h"

Player::Player(const glm::vec3 pos) : Entity(pos) {
    idBaseThank = loadOBJ("assets/thisThank.obj");
    idBaseCanon = loadOBJ("assets/thisThankCanon.obj");
    

}

Player::~Player() {
    glDeleteLists(idBaseThank, 1);
}

void Player::movement(bool forward) {
    speed = 0.1;
    if(forward) {
        position.x += speed * cos(rotation * (M_PI / 180));
        position.z -= speed * sin(rotation * (M_PI / 180));
    } else {
    
        position.x -= speed * cos(rotation * (M_PI / 180));
        position.z += speed * sin(rotation * (M_PI / 180));
    }
}

void Player::drawEntity() {
    glPushMatrix();

        glTranslatef(position.x, position.y, position.z);
        glRotatef(rotation, 0, 1, 0);
        drawAxe();
        glRotatef(90,0,1,0);
        glCallList(idBaseThank);
        glRotatef( canonRotation,0,1,0);
        glCallList(idBaseCanon);
    glPopMatrix();
    for(Projectile *p : projectile){
        p->draw();
    }
}

void Player::createProjectile() {
    projectile.push_back(new Projectile(rotation + canonRotation, position));
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