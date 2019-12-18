//
// Created by ssohy on 12/13/2019.
//

#include "Enemy.h"
#include "../Utils/glUtils.h"


Enemy::Enemy(const glm::vec3 &position, std::vector<Node> nMap, int planeSize) : Entity(position) {
    idBaseThank = loadOBJ("assets/thisThank.obj");
    idBaseCanon = loadOBJ("assets/thisThankCanon.obj");
    pathFinding = new aStar(nMap, planeSize);
    alive=true;
}

void Enemy::movement(glm::vec3 playerPos) {
    if(sqrt(pow(position.x - playerPos.x, 2) + pow(position.z - playerPos.z, 2)) <= 14.0) {
        if ((timeLastCheck + timeBetweenCheck) < SDL_GetTicks()) {
            pathFinding->FindPath(position, playerPos);
            if(pathFinding->foundPath.size() >= 4) {
                timeLastCheck = SDL_GetTicks();
                glm::vec3 destination(pathFinding->foundPath.at(0).getX() - pathFinding->foundPath.at(1).getX(),
                                      playerPos.y,
                                      pathFinding->foundPath.at(0).getY() - pathFinding->foundPath.at(1).getY());
                //glm::vec3 enemypos( pathFinding->foundPath.at(1).getX() - pathFinding->foundPath.at(0).getX(),playerPos.y,pathFinding->foundPath.at(0).getY());
                if (destination.x == 1 && destination.z == 0) {
                    rotation = 270;
                } else if (destination.x == -1 && destination.z == 0) {
                    rotation = 90;
                }
                    /*else if(destination.x == 1 && destination.z == 1){
                        rotation = 180 + (45 * 180.0 / M_PI);
                    }*/
                else if (destination.x == 0 && destination.z == 1) {
                    rotation = 180;
                }
                    /*else if(destination.x == -1 && destination.z == 1){
                        rotation = 90 + ( 45 * 180.0 / M_PI);
                    }
                    else if(destination.x == 1 && destination.z == -1){
                        rotation = 270 + (45 * 180 / M_PI);
                    }*/
                else if (destination.x == 0 && destination.z == -1) {
                    rotation = 0;
                }
                /*else if(destination.x == -1 && destination.z == -1){
                    rotation = 45 * 180.0 / M_PI;
                }*/


                if (rotation == 270) {
                    position.x -= 0.08;
                } else if (rotation == 90) {
                    position.x += 0.08;
                } else if (rotation == 0) {
                    position.z += 0.08;
                } else if (rotation == 180) {
                    position.z -= 0.08;
                }
            }
            /*else if(pathFinding->foundPath.size() != 0){

                position.x = position.x - 0.1 * cos(rotation );
                position.z = position.z + 0.1 * sin(rotation);
            }
            /*float normalA = sqrt(pow(destination.x,2) + pow(destination.y,2) + pow(destination.z,2));
            float normalB = sqrt(pow(enemypos.x,2) + pow(enemypos.y,2) + pow(enemypos.z,2));
            float ab = (enemypos.x * destination.x) + (enemypos.y * destination.y) + (enemypos.z * destination.z);
            float tempA = ab / (normalA * normalB);
            float angle = acos(tempA) * 180.0 / M_PI;
            if(pathFinding->foundPath.at(1).getX() - pathFinding->foundPath.at(0).getX() < 0)
                rotation = -angle ;
            else
                rotation = angle ;
            std::cout << "bob";*/
        }
    }



}

void Enemy::drawEntity() {
    glPushMatrix();

    glTranslatef(position.x + 0.5, position.y + 0.05, position.z);
    glRotatef(rotation, 0, 1, 0);
    glScalef(0.2f,0.2f,0.2f);
    glColor3f(0,0,1);
    glCallList(idBaseThank);
    glRotatef( canonRotation,0,1,0);
    glCallList(idBaseCanon);
    glPopMatrix();
}

void Enemy::chase(glm::vec3 pos) {

}




void Enemy::setPos(const glm::vec3 &pos) {
    Entity::setPos(pos);
}
const glm::vec3 &Enemy::getPos() const {
    return Entity::getPos();
}
float Enemy::getRotation() const {
    return Entity::getRotation();
}
void Enemy::setRotation(float rotation) {
    Entity::setRotation(rotation);
}
float Enemy::getCanonRotation() const {
    return Entity::getCanonRotation();
}
void Enemy::setCanonRotation(float canonRotation) {
    Entity::setCanonRotation(canonRotation);
}

aStar *Enemy::getPathFinding() const {
    return pathFinding;
}
