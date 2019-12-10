//
// Created by ssohy on 12/10/2019.
//

#include "Camera.h"

void Camera::moveCam(Player* player,int viewType) {
    
    switch (viewType){
        case 1:
            camPos.x = player->getPos().x+cos(player->getRotation() * M_PI / 180) * player->getSpeed()-10;
            camPos.z = player->getPos().z+sin(player->getRotation() * M_PI / 180) * player->getSpeed();
            gluLookAt(camPos.x, camPos.y, camPos.z, player->getPos().x, 0, player->getPos().z, 0, 1, 0);
            break;
        case 2:
            break;
        default:
            break;
    }
}




Camera::Camera(Player* player){
    camPos = glm::vec3((player->getPos().x+10),10,(player->getPos().z +10));
    rotAngle = player->getRotation();
    distance = 5;
    lastX =0;
    lastY=0;
}