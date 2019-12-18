//
// Created by ssohy on 12/13/2019.
//

#ifndef RUSTBUCKETS_ENEMY_H
#define RUSTBUCKETS_ENEMY_H


#include "Entity.h"
#include "../Utils/Pathfinding/aStar.h"
class Enemy : public Entity {

private:
    bool canShoot;
    aStar* pathFinding;
    float timeLastCheck = 0;
    float timeBetweenCheck = 50;
    float fireRate = 750;
    float lastFire = 0;
    GLuint idBaseThank = 0;
    GLuint idBaseCanon = 0;
public:
    explicit Enemy(const glm::vec3 &position, std::vector<Node> nMap, int planeSize);
    
    
    void chase(glm::vec3 pos);
    
    bool shoot();
    
    void movement(glm::vec3 playerPos);
    
    void drawEntity() override;


    aStar *getPathFinding() const;

    const glm::vec3 &getPos() const override;
    
    float getRotation() const override;
    
    void setRotation(float rotation) override;
    
    float getCanonRotation() const override;
    
    void setCanonRotation(float canonRotation) override;
    
    void setPos(const glm::vec3 &pos) override;

    ~Enemy();
};


#endif //RUSTBUCKETS_ENEMY_H
