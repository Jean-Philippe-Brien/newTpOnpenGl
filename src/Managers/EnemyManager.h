//
// Created by jean- on 2019-12-17.
//

#ifndef RUSTBUCKETS_ENEMYMANAGER_H
#define RUSTBUCKETS_ENEMYMANAGER_H

#include "../Utils/Include.h"
#include "../Classes/Enemy.h"
#include "../Utils/Pathfinding/Node.h"
#include "../Managers/ProjectileManager.h"

class EnemyManager {
private:
    std::vector<Enemy *> enemy;
    int maxEnemyCount;
    int timeBeforeLastSpawn;
    int timeBetweenNextSpawn;
    int planeSize;
    std::vector<Node> nodeMap;
    std::vector<glm::vec3> startPos;
    bool afficherPath = false;
public:
    void init(std::vector<Node> *nodeMap, int planeSize);
    void update(glm::vec3 playerPos, ProjectileManager* pManager);
    void addEnemy();

    const std::vector<Enemy *> &getEnemy() const;

    bool isAfficherPath() const;

    void setAfficherPath(bool afficherPath);

};


#endif //RUSTBUCKETS_ENEMYMANAGER_H
