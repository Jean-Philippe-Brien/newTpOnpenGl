//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_ENTITY_H
#define MONPROJETSDL_ENTITY_H

#include "../Utils/Include.h"


class Entity {

protected:
    //Base Variables
    bool alive;
    float baseSpeed = 0.05;
    double hp=100;
    glm::vec3 position; //(xf,yf,zf)
    float canonSpeed = 0;
    float rotation = 0;
    float canonRotation = 0;

public:
    
    explicit Entity(const glm::vec3 &position);
    
    //Geter/Setter
    bool isAlive() const;
    
    void setIsAlive(bool isAlive);
    
    float getSpeed() const;
    
    void setSpeed(float speed);
    
    virtual const glm::vec3 &getPos() const;
    
    float getCanonSpeed() const;
    
    void setCanonSpeed(float canonSpeed);
    
    virtual float getRotation() const;
    
    virtual void setRotation(float rotation);
    
    virtual float getCanonRotation() const;
    
    virtual void setCanonRotation(float canonRotation);
    
    double getHp() const;
    
    void setHp(double hp);
    
    const glm::vec3 &getPosition() const;
    
    void setPosition(const glm::vec3 &position);

    virtual void movement();
    
    virtual void drawEntity();
    
    //called everytime an entity shoots
    void shoot(int type);
    
    void gotHit();
    
    void isDead();
    
    
    virtual void setPos(const glm::vec3 &pos);
    
};


#endif //MONPROJETSDL_ENTITY_H
