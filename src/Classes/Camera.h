//
// Created by ssohy on 12/10/2019.
//

#ifndef RUSTBUCKETS_CAMERA_H
#define RUSTBUCKETS_CAMERA_H

#include "../Utils/Include.h"
#include "Player.h"

class Camera {

public:
    int camType;
    
    glm::vec3 camPos;
    float camAngle;
    float rotAngle;
    float distance = 5;
    float tempX;
    float tempY;
    glm::vec3 fpsCamPos;
    glm::vec2 fpsCamRot;
    float fpsCamAngle;
    float lastX,lastY;
    
    
    Camera(Player* player);
    

    void moveCam(Player* player,int viewTyconst);

    void setDistance(float distance);
};


#endif //RUSTBUCKETS_CAMERA_H
