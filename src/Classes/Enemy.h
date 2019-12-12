//
// Created by ssohy on 12/11/2019.
//

#ifndef RUSTBUCKETS_ENEMY_H
#define RUSTBUCKETS_ENEMY_H

#include "../Utils/Include.h"
#include "../Utils/glUtils.h"
#include "Entity.h"
#include "Player.h"


class Enemy : public Entity{
private:
    float fireRate = 200;
    float lastFire = 0;
    GLuint idBaseThank = 0;
    GLuint idBaseCanon = 0;
public:
    explicit Enemy(const glm::vec3 &position);
    void spawn(glm::vec3 pos);
    void update(Player* player);
    void wander();
    void chaseTarget();
    void findPathToTarget();
    
    
    //Getter & Setter
    float getIsAlive() const override;
    void setIsAlive(float isAlive) override;
    void movement(Player* player);
    void setPosition(const glm::vec3 &pos) ;
    float getRotation() const override;
    void setRotation(float rotation) override;
    void drawEntity() override;
    float getCanonRotation() const override;
    void setCanonRotation(float canonRotation) override;
    
    virtual ~Enemy();
};


#endif //RUSTBUCKETS_ENEMY_H
