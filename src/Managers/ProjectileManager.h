//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_PROJECTILEMANAGER_H
#define MONPROJETSDL_PROJECTILEMANAGER_H

#include "../Utils/Include.h"
#include "../Classes/Projectile.h"
#include "../Classes/Player.h"
#include "../Classes/Enemy.h"
#include "CollisionManager.h"
class ProjectileManager {
private:
    std::vector<Projectile*> projectile;
public:
    ProjectileManager();
    void checkBulletAlive();
    void createProjectile(Player *player);
    void createProjectile(float rotation, glm::vec3 pos);
    void init();
    void update(CollisionManager* cm,Player* player, std::vector<Enemy*> e);
    ~ProjectileManager();
};


#endif //MONPROJETSDL_PROJECTILEMANAGER_H
