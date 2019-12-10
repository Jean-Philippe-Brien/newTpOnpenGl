//
// Created by ssohy on 12/10/2019.
//

#ifndef RUSTBUCKETS_CAMERA_H
#define RUSTBUCKETS_CAMERA_H

#include "../Utils/Include.h"
#include "../Player.h"

class Camera {

public:
    
    glm::vec3 camPos;
    float camAngle;
    float rotAngle;
    float distance;
    float lastX,lastY;
    
    
    Camera(Player* player);
    
    
    void moveCam(Player* player,int viewTyconst);
};


#endif //RUSTBUCKETS_CAMERA_H
