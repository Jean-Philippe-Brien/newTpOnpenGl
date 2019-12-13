//
// Created by ssohy on 12/13/2019.
//

#ifndef RUSTBUCKETS_ENEMY_H
#define RUSTBUCKETS_ENEMY_H


#include "Entity.h"

class Enemy : public Entity {

private:
    float fireRate = 200;
    float lastFire = 0;
    GLuint idBaseThank = 0;
    GLuint idBaseCanon = 0;
public:
    explicit Enemy(const glm::vec3 &position);
    
    
    
   void chase(glm::vec3 pos);
   void shoot();
    
    
    const glm::vec3 &getPos() const override;
    
    float getRotation() const override;
    
    void setRotation(float rotation) override;
    
    float getCanonRotation() const override;
    
    void setCanonRotation(float canonRotation) override;
    
    void movement() override;
    
    void drawEntity() override;
    
    void setPos(const glm::vec3 &pos) override;
};


#endif //RUSTBUCKETS_ENEMY_H
