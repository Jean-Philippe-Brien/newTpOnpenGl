//
// Created by jean- on 2019-12-07.
//

#ifndef MONPROJETSDL_PLAYER_H
#define MONPROJETSDL_PLAYER_H
#include <GL/gl.h>
#include <GL/glu.h>
#include <vector>
#include <fstream>
#include "Classes/Entity.h"
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cstdio>
#include <iostream>
#include "Utils/glUtils.h"
#include <string>
#include "Classes/Projectile.h"

class Player: Entity {
private:
    std::vector<Projectile*> projectile;
    float fireRate = 1000;
    float lastFire = 0;
    GLuint idBaseThank = 0;
    GLuint idBaseCanon = 0;
public:
    Player(const glm::vec3 pos);
    void movement(bool forward);
    void setPos(const glm::vec3 &pos) override;
    const glm::vec3 &getPos() const override;
    float getRotation() const override;
    void setRotation(float rotation) override;
    void drawEntity() override;
    float getCanonRotation() const override;
    void setCanonRotation(float canonRotation) override;
    void createProjectile();
    ~Player();

    float getFireRate1() const;

    void setFireRate1(float fireRate);

    float getLastFire() const;

    void setLastFire(float lastFire);

};


#endif //MONPROJETSDL_PLAYER_H
