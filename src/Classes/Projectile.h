//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_PROJECTILE_H
#define MONPROJETSDL_PROJECTILE_H

#include "../Utils/Include.h"
#include "../Utils/glUtils.h"

class Projectile {
private:
    float timeInstance;
    float speed = 0.3;
    float anglePlayerCanon = 0;
    float timeAlive = 1000; // en milliseconde
    bool isAlive = true;
    glm::vec3 position;

public:
    bool getIsAlive() const;

    void isProjectileAlive();
    static GLuint idProjectile;
    Projectile(float anglePlayerCanon, glm::vec3 positionPlayer);
    void draw();
    void movement();
};


#endif //MONPROJETSDL_PROJECTILE_H
