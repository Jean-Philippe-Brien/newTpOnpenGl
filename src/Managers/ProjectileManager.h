//
// Created by ssohy on 12/9/2019.
//

#ifndef MONPROJETSDL_PROJECTILEMANAGER_H
#define MONPROJETSDL_PROJECTILEMANAGER_H

#include "../Utils/Include.h"
#include "../Classes/Projectile.h"
#include "../Player.h"
class ProjectileManager {
private:
    std::vector<Projectile*> projectile;
public:
    ProjectileManager();
    void checkBulletAlive();
    void createProjectile(Player *player);
    void init();
    void update();
    ~ProjectileManager();
};


#endif //MONPROJETSDL_PROJECTILEMANAGER_H
