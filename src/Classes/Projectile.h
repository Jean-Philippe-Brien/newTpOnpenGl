//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_PROJECTILE_H
#define MONPROJETSDL_PROJECTILE_H

#include "../Utils/Include.h"
#include "../Utils/glUtils.h"

class Projectile {
private:

    float speed = 0.1;
    float anglePlayerCanon = 0;

    glm::vec3 position;

public:
    static GLuint idProjectile;
    Projectile(float anglePlayerCanon, glm::vec3 positionPlayer);
    void draw();
    void movement();
};


#endif //MONPROJETSDL_PROJECTILE_H
