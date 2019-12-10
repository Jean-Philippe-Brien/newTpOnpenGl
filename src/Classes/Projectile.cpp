//
// Created by ssohy on 12/9/2019.
//

#include "Projectile.h"
GLuint Projectile::idProjectile = 0;
Projectile::Projectile(float anglePlayerCanon, glm::vec3 positionPlayer): anglePlayerCanon(anglePlayerCanon), position(positionPlayer) {
    speed = 0.1;
    timeInstance = SDL_GetTicks();
}
void Projectile::isProjectileAlive(){
    isAlive = timeInstance + timeAlive < SDL_GetTicks();
}
void Projectile::draw() {
    glPushMatrix();

        glTranslatef(position.x, position.y + 2, position.z);
        glRotatef(this->anglePlayerCanon, 0, 1, 0);
        glTranslatef(5,0,0);
        drawAxe();
        glScaled(0.2,0.2,0.2);
        drawCube();
        //glCallList(idProjectile);
    glPopMatrix();
    movement();
}
void Projectile::movement() {
    position.x += speed * cos(anglePlayerCanon * (M_PI / 180));
    position.z -= speed * sin(anglePlayerCanon * (M_PI / 180));
}

bool Projectile::getIsAlive() const {
    return isAlive;
}
