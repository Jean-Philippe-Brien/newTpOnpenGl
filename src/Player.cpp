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
        glScalef(0.2f,0.2f,0.2f);
        glColor3f(0,0,1);
        glCallList(idBaseThank);
        glRotatef( canonRotation,0,1,0);
        glCallList(idBaseCanon);
    glPopMatrix();
    for(Projectile *p : projectile){
        p->draw();
        p->isProjectileAlive();
    }
    checkBulletAlive();
}

void Player::checkBulletAlive() {
    std::vector<int> temp;

    for(int i = 0; i < projectile.size(); i++){
        if(projectile[i]->getIsAlive()){
            temp.push_back(i);
        }
    }
    for(int i = 0; i < temp.size(); i++){
        projectile.erase(projectile.begin() + temp[i]);
    }

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

void Player::createProjectile() {
    float p = SDL_GetTicks();
    if(this->lastFire + fireRate < p ) {
        lastFire = SDL_GetTicks();
        projectile.push_back(new Projectile(rotation + canonRotation, position));
    }
}

float Player::getFireRate1() const {
    return fireRate;
}

void Player::setFireRate1(float fireRate) {
    Player::fireRate = fireRate;
}

float Player::getLastFire() const {
    return lastFire;
}

void Player::setLastFire(float lastFire) {
    Player::lastFire = lastFire;
}