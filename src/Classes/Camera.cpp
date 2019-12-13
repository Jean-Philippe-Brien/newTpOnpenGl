//
// Created by ssohy on 12/10/2019.
//

#include "Camera.h"

void Camera::moveCam(Player* player,int viewType) {
    
    switch (viewType){
        case 1:

            camPos.x = player->getPos().x - distance * cos(player->getRotation() * (M_PI / 180));
            camPos.z = player->getPos().z + distance * sin(player->getRotation() * (M_PI / 180));
            gluLookAt(camPos.x, camPos.y, camPos.z, player->getPos().x, 0, player->getPos().z, 0, 1, 0);
            break;
        case 2:
            camPos.x = player->getPos().x - 3 * cos(player->getRotation() * (M_PI / 180));
            camPos.z = player->getPos().z + 3 * sin(player->getRotation() * (M_PI / 180));
            gluLookAt(camPos.x, 2, camPos.z, player->getPos().x+1, 0.5, player->getPos().z, 0, 1, 0);
        
            //Tank top mounted static fps camera
            break;
        default:
            break;
    }
}





Camera::Camera(Player* player,int camType){
    switch (camType){
        case 1:
            camPos = glm::vec3((player->getPos().x),10,(player->getPos().z));
            rotAngle = player->getRotation();
            distance = 5;
            lastX =0;
            lastY=0;
            break;
        case 2:
            //Tank top mounted Fps camera
            break;
        default:
            break;
    }
}

void Camera::setDistance(float distance) {
    if(this->distance + distance > 0 &&  this->distance + distance <= 10)
    Camera::distance += distance;
}
