//
// Created by ssohy on 12/9/2019.
//

#include "Projectile.h"
GLuint Projectile::idProjectile = 0;
Projectile::Projectile(float anglePlayerCanon, glm::vec3 positionPlayer): anglePlayerCanon(anglePlayerCanon), position(positionPlayer) {
    position.x = position.x + 0.4 * cos(anglePlayerCanon * (M_PI / 180));
    position.z = position.z - 0.4 * sin(anglePlayerCanon * (M_PI / 180));
    position.y += 0.25;
    timeInstance = SDL_GetTicks();
}
void Projectile::isProjectileAlive(){
    isAlive = !timeInstance + timeAlive < SDL_GetTicks();
}
void Projectile::draw() {
    if(isAlive) {
        movement();
        glColor3f(255, 0, 0);
        glPushMatrix();
        glTranslatef(position.x, position.y + 0.2, position.z);
        glRotatef(this->anglePlayerCanon, 0, 1, 0);

        glTranslatef(0.55,0.18,0);
        glScaled(0.03,0.03,0.03);
        drawCube();
        //glCallList(idProjectile);
        glPopMatrix();
    }

}
void Projectile::movement() {

    position.x += speed * cos(anglePlayerCanon * (M_PI / 180));
    position.z -= speed * sin(anglePlayerCanon * (M_PI / 180));

}

bool Projectile::getIsAlive() const {
    return isAlive;
}

const glm::vec3 &Projectile::getPosition() const {
    return position;
}

void Projectile::setIsAlive(bool isAlive) {
    Projectile::isAlive = isAlive;
}
