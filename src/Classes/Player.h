//
// Created by jean- on 2019-12-07.
//

#ifndef MONPROJETSDL_PLAYER_H
#define MONPROJETSDL_PLAYER_H

#include "../Utils/Include.h"
#include "Entity.h"
#include "../Utils/glUtils.h"
#include "Projectile.h"
#include "../Managers/CollisionManager.h"


class Player: public Entity {
private:
    int life = 100;
    int maxLife = 100;
    float tempX,tempY;
    float fireRate = 200;
    float lastFire = 0;
    GLuint idBaseThank = 0;
    GLuint idBaseCanon = 0;
public:
    explicit Player(const glm::vec3 pos);
    void movement(bool forward, CollisionManager *cm);
    void afficherVieGui();
    bool isHit();
    
    //Getter / Setter
    void setPos(const glm::vec3 &pos) override;
    const glm::vec3 &getPos() const override;
    float getRotation() const override;
    void setRotation(float rotation) override;
    void drawEntity() override;
    float getCanonRotation() const override;
    void setCanonRotation(float canonRotation) override;
    float getTempX() const;
    void setTempX(float tempX);
    float getTempY() const;
    void setTempY(float tempY);
    float getFireRate1() const;
    float getLastFire() const;
    void setLastFire(float lastFire);
    ~Player();
    
};


#endif //MONPROJETSDL_PLAYER_H
