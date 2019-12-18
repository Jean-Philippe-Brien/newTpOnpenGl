//
// Created by jean- on 2019-12-17.
//

#include "EnemyManager.h"

void EnemyManager::init(std::vector<Node> *nodeMap, int planeSize) {
    this->nodeMap = *nodeMap;
    this->planeSize = planeSize;
    for(Enemy* e : enemy){

    }
}

void EnemyManager::update(glm::vec3 playerPos, ProjectileManager* pManager) {
    std::vector<int> temp;
    for(int i = 0; i < enemy.size(); i++){
        if(!enemy[i]->isAlive()){
            temp.push_back(i);
        }
    }
    for(int i = 0; i < temp.size(); i++){
        //delete enemy.at(temp[i]);
        enemy.erase(enemy.begin() + temp[i]);

    }
    if(enemy.size() == 0){
        addEnemy();
    }
    for(Enemy* e : enemy){
        if(e->isAlive()) {
            e->movement(playerPos);
            if (e->shoot()) {
                pManager->createProjectile(e->getRotation() - 90, e->getPosition());
            }

            e->drawEntity();
        }
    }
}

void EnemyManager::addEnemy() {
    enemy.push_back(new Enemy(glm::vec3(10,0,10), nodeMap, 40));
}

const std::vector<Enemy *> &EnemyManager::getEnemy() const {
    return enemy;
}
